#include "enemy.h"
#include <stdlib.h>
#include <iostream>

#pragma once

class flyingBook : public Enemy
{
private:
  sf::Vector2f direction;
public:
  flyingBook();
  ~flyingBook();
  void update(sf::Time deltaTime);
  void addWaypoint();
};
