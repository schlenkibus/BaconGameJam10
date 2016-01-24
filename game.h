#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Animation.h"
#include "AnimatedSprite.h"
#include "resources.h"
#include "player.h"
#include <iostream>
#include "flyingBook.h"
#include "level.h"
#include "kitchen.h"
#include "prison.h"

class Game
{
private:
  Player player;
  sf::Music mus;
  enum gameState {ingame, dead, clear, pause};
  enum activeLevel {lvl1, lvl2, lvl3};
  activeLevel aLevel;
  Animation * testAnim;
  AnimatedSprite * testPlayer;
  Resources gameRS;
  sf::Clock gameTimer, fpsTimer;
  libaryLevel level1;
  kitchen level2;
  prison level3;
public:
  Game();
  ~Game();
  void update();
  void render(sf::RenderWindow& window);
  void setLevel(int i);
};
