#include "enemy.h"
#include <stdlib.h>
#include <iostream>

#pragma once

class flyingBook : public Enemy
{
private:
  sf::Vector2f direction;
  bool dead;
public:
  void kill();
  flyingBook();
  ~flyingBook();
  void update(sf::Time deltaTime);
  void addWaypoint();
  sf::Vector2f getPos();
};
