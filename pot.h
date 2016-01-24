#include "enemy.h"

#pragma once

class Pot : public Enemy
{
private:
  bool dead, tempWay;
  Animation left;
public:
  Pot();
  void kill();
  void update(sf::Time deltaTime);
  void addWaypoint();
};
