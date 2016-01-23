#include "resources.h"
#include "Animation.h"
#include "AnimatedSprite.h"

#pragma once

class Door
{
private:
  Resources doorRS;
  AnimatedSprite sprite, trigger;
  Animation openDoor, idle, triggerFlash;
  bool locked;
public:
  Door();
  AnimatedSprite& getSprite();
  AnimatedSprite& getTriggerSprite();
  void update(sf::Time deltaTime);
  void setPosition(sf::Vector2f pos);
};
