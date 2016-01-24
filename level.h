#include "resources.h"
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.h"
#include "Animation.h"
#include "flyingBook.h"
#include <fstream>
#include "player.h"
#include "spiderWeb.h"
#include "fire.h"
#include "bossBook.h"

#pragma once

#define libraryEnemys 3

class libaryLevel //To be added: Doors, Platforms, Key etc.
{
private:
  Player * p_player;
  Resources libraryRS;
  sf::Sprite backG, Floor;

  bossBook boss;

  WebPickup pickup1, pickup2, pickup3;
  pickupFire fire1, fire2, fire3;

  sf::FloatRect eFR1, eFR2, eFR3, t1, t2, t3;

  sf::Sprite platform1, platform2, platform3, platform4;
  flyingBook enemy1, enemy2, enemy3;
  std::fstream levelData;
public:
  libaryLevel();
  void update(sf::Time deltaTime);
  void draw(sf::RenderWindow& window);
  void setPlayerPointer(Player& p);
};
