#include "resources.h"
#include "SFML/Graphics.hpp"

#pragma once

class Key
{
private:
  Resources tex;
  sf::Sprite sprite;
public:
  Key();
  sf::Vector2f getPos();
  sf::Sprite& getSprite();
  void setPosition(sf::Vector2f p);
};
