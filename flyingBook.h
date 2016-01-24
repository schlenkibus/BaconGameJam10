#include "enemy.h"
#include <stdlib.h>
#include <iostream>
#include "AnimatedSprite.h"
#include "Animation.h"

#pragma once

class flyingBook : public Enemy
{
private:
  sf::Vector2f direction;
  bool dead;
  Animation left, right;
public:
  void kill();
  flyingBook();
  ~flyingBook();
  void update(sf::Time deltaTime);
  void addWaypoint();
  sf::Vector2f getPos();
};
