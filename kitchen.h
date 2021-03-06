#pragma once

#include "resources.h"
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.h"
#include "Animation.h"
#include <fstream>
#include "player.h"
#include "spiderWeb.h"
#include "bossKnife.h"
#include "pot.h"

class kitchen
{
private:
  Player * p_player;

  Resources rs;
  sf::Sprite backG, Floor;

  bossKnife boss;

  WebPickup pickup1, pickup2, pickup3;

  sf::Sprite platform1, platform2, platform3;
  Pot enemy1, enemy2, enemy3;
  std::fstream levelData;
public:
  kitchen();
  void update(sf::Time deltaTime);
  void draw(sf::RenderWindow &window);
  void setPlayerPointer(Player& p);
};
