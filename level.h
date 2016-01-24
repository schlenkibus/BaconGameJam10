#include "resources.h"
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.h"
#include "Animation.h"
#include "flyingBook.h"
#include <fstream>
#include "door.h"
#include "key.h"
#include "player.h"

#pragma once

#define libraryEnemys 3

class libaryLevel //To be added: Doors, Platforms, Key etc.
{
private:
  Player * p_player;
  Resources libraryRS;
  sf::Sprite backG;
  sf::Sprite Floor;
  Door door;
  sf::Sprite platform1, platform2, platform3, platform4;
  flyingBook enemy1, enemy2, enemy3;
  std::fstream levelData;
  Key key;
public:
  libaryLevel();
  void update(sf::Time deltaTime);
  void draw(sf::RenderWindow& window);
  void setPlayerPointer(Player& p);
};
