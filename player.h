#pragma once

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "AnimatedSprite.h"
#include <iostream>
#include "resources.h"
#include "physicsComp.h"

class Player
{
private:
  Resources playerResource;
  AnimatedSprite playerRender;
  Animation idleAnim;
  enum playerAnim {idle, jump, moveLeft, moveRight};
  sf::Vector2f pos;
public:
  PhysicsComponent physCom;
  Player();
  ~Player();
  void update(sf::Time deltaTime);
  AnimatedSprite& getSprite();
  sf::Vector2f getPos();
  void setPosition(sf::Vector2f nP);
};
