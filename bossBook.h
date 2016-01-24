#include "resources.h"
#include "Animation.h"
#include "AnimatedSprite.h"

#pragma once

class bossBook
{
private:
  Animation hit, idle, dead;
  Resources rs;
  int health;
  bool canBeHit, red;
  sf::Clock renderClock, bossClock;
public:
  AnimatedSprite sprite;
  bossBook();
  void update(sf::Time deltaTime);
  void onHit();
  bool alive;
};
