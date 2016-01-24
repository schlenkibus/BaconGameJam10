#include "player.h"

Player::Player()
{

  pos.x = 100;
  pos.y = 700;
  playerResource.loadFromFileAndStore("player/wand-anims/wand-idle/idle.png", "player_idle","textures");
  playerResource.loadFromFileAndStore("key.png", "key", "textures");
  playerResource.loadFromFileAndStore("key_hud_not.png", "key_not", "textures");
  idleAnim.setSpriteSheet(playerResource.getTextureFromMap("player_idle"));

  idleAnim.addFrame(sf::IntRect(0, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(36, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(70, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(105, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(138, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(173, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(207, 0, 34, 127));
  idleAnim.addFrame(sf::IntRect(240, 0, 34, 127));
  playerRender.setAnimation(idleAnim);
  playerRender.setFrameTime(sf::seconds(0.2f));
  playerRender.setOrigin(17.5f, 135);
  physCom.setPosition(pos);

  hudKey.setPosition(sf::Vector2f(50, 50));
  hudKey.setTexture(playerResource.getTextureFromMap("key_not"));

  key = false; life = 100; BcanGetDamage = true;
  red = false;
}

Player::~Player()
{

}

void Player::update(sf::Time deltaTime)
{
  physCom.update(deltaTime); //for gravity
  playerRender.update(deltaTime); //For animation
  playerRender.setPosition(physCom.getPos()); //for drawin the stuff
  if (playerClock.getElapsedTime().asSeconds() >= 1.f && BcanGetDamage == false)
  {
    BcanGetDamage = true;
    playerClock.restart();
  }
  else
  {
    if(renderClock.getElapsedTime().asSeconds() >= 0.05f)
    {
      if(red)
      {
        playerRender.setColor(sf::Color::Transparent);
      }
      else
      {
        playerRender.setColor(sf::Color::Red);
      }
      renderClock.restart();
    }
  }
}

AnimatedSprite& Player::getSprite()
{
  return playerRender;
}

sf::Vector2f Player::getPos()
{
  return pos;
}

sf::Sprite& Player::getHud()
{
  return hudKey;
}

void Player::pickupKey()
{
  key = true;
  hudKey.setTexture(playerResource.getTextureFromMap("key"));
}

void Player::kill()
{
  //TODO DIE CODE INSTERT
}

int Player::getLife()
{
  return life;
}

void Player::setLife(int l)
{
  life = l;
  BcanGetDamage = false;
}

bool Player::canGetDamage()
{
  return BcanGetDamage;
}
