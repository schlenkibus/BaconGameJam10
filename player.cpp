#include "player.h"

Player::Player()
{

  pos.x = 100;
  pos.y = 700;
  playerResource.loadFromFileAndStore("player/wand-anims/wand-idle/idle.png", "player_idle","textures");
  playerResource.loadFromFileAndStore("player/wand-anims/wand-action/nothing.png", "actionNone", "textures");
  playerResource.loadFromFileAndStore("player/wand-anims/wand-action/spider.png", "actionSpiderR", "textures");
  playerResource.loadFromFileAndStore("player/fire.png", "actionFireR", "textures");
  playerResource.loadFromFileAndStore("projectile.png", "projectile", "textures");

  projectile.setTexture(playerResource.getTextureFromMap("projectile"));

  idleAnim.setSpriteSheet(playerResource.getTextureFromMap("player_idle"));
  idleAnim.addFrame(sf::IntRect(0, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(36, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(70, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(105, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(138, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(173, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(207, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(240, 0, 34, 127));

  isFlame = false;

  actionNone.setSpriteSheet(playerResource.getTextureFromMap("actionNone"));
  actionNone.addFrame(sf::IntRect(39, 0, 34, 128));

  actionFire.setSpriteSheet(playerResource.getTextureFromMap("actionFireR"));
  actionFire.addFrame(sf::IntRect(42, 0, 70, 127));

  actionSpider.setSpriteSheet(playerResource.getTextureFromMap("actionSpiderR"));
  actionSpider.addFrame(sf::IntRect(39, 0, 72, 128));

  playerRender.setAnimation(idleAnim);
  playerRender.setFrameTime(sf::seconds(0.2f));
  playerRender.setOrigin(17.5f, 135);
  physCom.setPosition(pos);

  life = 100; BcanGetDamage = true; gotDamage = false;
  red = false;

  currentAction = none;

  spiderWebs = 0; stones = 0; fireBalls = 0;

  actionPlaying = false;
}

Player::~Player()
{

}

void Player::update(sf::Time deltaTime)
{
  physCom.update(deltaTime); //for gravity
  playerRender.update(deltaTime); //For animation
  playerRender.setPosition(physCom.getPos()); //for drawin the stuff

  if(physCom.getVelo() < 0)
  {
    playerDirection = facingLeft;
  }
  else if(physCom.getVelo() > 0)
  {
    playerDirection = facingRight;
  }
  //Actioncode
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
  {
    doAction();
  }
  if(actionPlaying)
  {
    switch(currentAction)
    {
      case playerAction::none:
        if(actionClock.getElapsedTime().asSeconds() >= 2.3f)
        {
          playerRender.setAnimation(idleAnim);
          actionPlaying = false;
        }
      break;
      case playerAction::spider:
        if(actionClock.getElapsedTime().asSeconds() >= 1.f)
        {
          playerRender.setAnimation(idleAnim);
          actionPlaying = false;
        }
      break;
      case playerAction::fire:
        if(actionClock.getElapsedTime().asSeconds() >= 1.2f)
        {
          playerRender.setAnimation(idleAnim);
          isFlame = false;
          actionPlaying = false;
        }
      break;
    }
  }

  //Spider
  if(projectileShot)
  {
    if(projectileDirection == facingRight)
    {
      projectile.move(5, 0);
    }
    else
    {
      projectile.move(-5, 0);
    }
  }
  //Damagecode
  if (gotDamage == true)
  {
    if(renderClock.getElapsedTime().asSeconds() >= 0.05f)
    {
      if(red)
      {
        playerRender.setColor(sf::Color::White);
        red = false;
      }
      else
      {
        playerRender.setColor(sf::Color::Red);
        red = true;
      }
      renderClock.restart();
    }
    if(playerClock.getElapsedTime().asSeconds() >= 0.5f)
    {
      gotDamage = false;
      BcanGetDamage = true;
      playerClock.restart();
      playerRender.setColor(sf::Color::White);
    }
  }

  //Choose the Action
  if(fireBalls >= 3)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
      currentAction = playerAction::fire;
  if(spiderWebs >= 3)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
      currentAction = playerAction::spider;
  if(stones >= 3)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
      currentAction = playerAction::hammer;
}

void Player::destroyProjectile()
{
  projectileShot = false;
  projectile.setPosition(-200, -200);
}

bool Player::isShot()
{
  return projectileShot;
}

AnimatedSprite& Player::getSprite()
{
  return playerRender;
}

sf::Vector2f Player::getPos()
{
  return physCom.getPos();
}

void Player::kill()
{
  //TODO DIE CODE INSTERT HERE
}

int Player::getLife()
{
  return life;
}

void Player::setLife(int l)
{
  life = l;
  BcanGetDamage = false;
  gotDamage = true;
  playerClock.restart();
}

bool Player::canGetDamage()
{
  return BcanGetDamage;
}

void Player::doAction()
{
  if(actionPlaying == true)
    return;

  switch(currentAction)
  {
    case playerAction::none:
      playerRender.setAnimation(actionNone);
      actionPlaying = true;
      actionClock.restart();
    break;
    case playerAction::fire:
      playerRender.setAnimation(actionFire);
      actionPlaying = true;
      isFlame = true;
      actionClock.restart();
    break;
    case playerAction::hammer:
      playerRender.setAnimation(actionHammer);
      actionPlaying = true;
      actionClock.restart();
    break;
    case playerAction::spider:
      playerRender.setAnimation(actionSpider);
      actionPlaying = true;
      projectileShot = true;
      projectile.setPosition(playerRender.getPosition().x, playerRender.getPosition().y - 100);
      projectileDirection = playerDirection;
      actionClock.restart();
    break;
  }
}

void Player::pickupFire()
{
  fireBalls++;
}

void Player::pickupSpider()
{
  spiderWebs++;
}

void Player::pickupStone()
{
  stones++;
}

bool Player::isActionPlaying()
{
  return actionPlaying;
}

sf::Sprite& Player::getProjectile()
{
  return projectile;
}

PhysicsComponent& Player::getPhysCom()
{
  return physCom;
}

void Player::setPosition(sf::Vector2f nP)
{
  playerRender.setPosition(nP);
  //pos = nP;
}
