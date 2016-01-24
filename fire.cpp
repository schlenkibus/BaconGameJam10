#include "fire.h"

pickupFire::pickupFire()
{
  rs.loadFromFileAndStore("firePickup.png", "firePickup", "textures");
  idle.setSpriteSheet(rs.getTextureFromMap("firePickup"));
  idle.addFrame(sf::IntRect(10, 30, 50, 113));
  sprite.setAnimation(idle);
}

void pickupFire::update(sf::Time deltaTime)
{
  sprite.update(deltaTime);
}

AnimatedSprite& pickupFire::getSprite()
{
  return sprite;
}
