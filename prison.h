#pragma once

#include "resources.h"
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.h"
#include "Animation.h"
#include <fstream>
#include "player.h"
#include "endTrigger.h"

class prison
{
private:
  Player * p_player;

  Resources rs;
  sf::Sprite backG, Floor;
  wizzard wiz;
public:
  prison();
  void update(sf::Time deltaTime);
  void draw(sf::RenderWindow &window);
  void setPlayerPointer(Player& p);
};
