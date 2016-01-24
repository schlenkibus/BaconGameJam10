#include "resources.h"
#include "Animation.h"
#include "AnimatedSprite.h"

#pragma once

class pickupFire
{
private:
  Resources rs;
  AnimatedSprite sprite;
  Animation idle;
public:
  pickupFire();
  void update(sf::Time deltaTime);
  AnimatedSprite& getSprite();
};
