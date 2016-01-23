#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "AnimatedSprite.h"
#include "resources.h"
#include "player.h"
#include <iostream>
#include "flyingBook.h"
#include "level.h"

#pragma once

class Game
{
private:
  Player player;
  enum gameState {ingame, dead, clear, pause};
  Animation * testAnim;
  AnimatedSprite * testPlayer;
  Resources gameRS;
  sf::Clock gameTimer, fpsTimer;
  libaryLevel level1;
public:
  Game();
  ~Game();
  void update();
  void render(sf::RenderWindow& window);
};
