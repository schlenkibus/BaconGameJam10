#include "resources.h"
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.h"
#include "Animation.h"
#include "flyingBook.h"
#include <fstream>

#pragma once

#define libraryEnemys 3

class libaryLevel //To be added: Doors, Platforms, Key etc.
{
private:
  Resources libraryRS;
  sf::Sprite backG;
  sf::Sprite Floor;
  sf::Sprite platform1, platform2, platform3, platform4;
  flyingBook enemy1, enemy2, enemy3;
  std::fstream levelData;
public:
  libaryLevel();
  void update(sf::Time deltaTime);
  void draw(sf::RenderWindow& window);
};

class kitchen
{

};

class cellar
{

};

class prison
{

};
