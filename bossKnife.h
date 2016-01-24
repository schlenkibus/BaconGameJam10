#include "resources.h"
#include "Animation.h"
#include "AnimatedSprite.h"

#pragma once

class bossKnife
{
private:
  Resources rs;
  Animation idle, hit, Animdead, stickied1, stickied2;
  int health;
public:
  AnimatedSprite sprite;
  bossKnife();
  void onHit();
  void update(sf::Time deltaTime);
  bool dead;
};
