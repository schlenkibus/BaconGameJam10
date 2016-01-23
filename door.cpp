#include "door.h"

Door::Door()
{
  doorRS.loadFromFileAndStore("Door.png", "door", "textures");
  doorRS.loadFromFileAndStore("Trigger.png", "trigger", "textures");
  idle.setSpriteSheet(doorRS.getTextureFromMap("door"));
  triggerFlash.setSpriteSheet(doorRS.getTextureFromMap("trigger"));
  idle.addFrame(sf::IntRect(0, 0, 50, 150));
  triggerFlash.addFrame(sf::IntRect(0, 0, 75, 75));
  triggerFlash.addFrame(sf::IntRect(75, 0, 75, 75));
  triggerFlash.addFrame(sf::IntRect(150, 0, 75, 75));
  sprite.setAnimation(idle);
  trigger.setAnimation(triggerFlash);
  trigger.setFrameTime(sf::seconds(0.3f));
}

AnimatedSprite& Door::getSprite()
{
  return sprite;
}

AnimatedSprite& Door::getTriggerSprite()
{
  return trigger;
}

void Door::update(sf::Time deltaTime)
{
  sprite.update(deltaTime);
  trigger.update(deltaTime);
}

void Door::setPosition(sf::Vector2f pos)
{
  sprite.setPosition(pos);
  trigger.setPosition(pos.x - 50, pos.y + 75);
}
