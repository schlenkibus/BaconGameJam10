#include "resources.h"
#include "SFML/Graphics.hpp"

#pragma once

class WebPickup
{
private:
  Resources rsPickup;
  sf::Sprite sprite;
public:
  WebPickup();
  sf::Sprite& getSprite();
};

class WebShot
{

};
