#include "player.h"

Player::Player()
{

  pos.x = 100;
  pos.y = 565;
  playerResource.loadFromFileAndStore(std::string("wand1.png"),
                                        std::string("player_idle"),
                                        std::string("textures"));
  idleAnim.setSpriteSheet(playerResource.getTextureFromMap("player_idle"));
  idleAnim.addFrame(sf::IntRect(0, 0, 35, 102));
  //idleAnim.addFrame(sf::IntRect(100, 0, 100, 200));
  playerRender.setAnimation(idleAnim);
  playerRender.setFrameTime(sf::seconds(0.3f));

  physCom.setPosition(pos);
}

Player::~Player()
{

}

void Player::update(sf::Time deltaTime)
{
  physCom.update(deltaTime); //for gravity
  playerRender.update(deltaTime); //For animation
  playerRender.setPosition(physCom.getPos()); //for drawin the stuff
}

AnimatedSprite& Player::getSprite()
{
  return playerRender;
}

sf::Vector2f Player::getPos()
{
  return pos;
}
