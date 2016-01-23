#include "enemy.h"
#include <stdlib.h>

#pragma once

class flyingBook : public Enemy
{
private:
  sf::Vector2f direction;
public:
  flyingBook();
  ~flyingBook();
  void update(sf::Time deltaTime);
  void addWaypoint(sf::Vector2f pos);
};
