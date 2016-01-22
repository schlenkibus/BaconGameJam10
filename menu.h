#include "SFML/Graphics.hpp"
#include <memory>
#include <list>
#include "resources.h"

#pragma once

class Menu
{
private:
  Resources rs;
  sf::Sprite backg;
public:
  void draw(sf::RenderWindow &window);
  void update();
  Menu();
  ~Menu();
};
