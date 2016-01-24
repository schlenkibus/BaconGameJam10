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
  sf::Sprite hudKey;
  enum playerAnim {idle, jump, moveLeft, moveRight};
  sf::Vector2f pos;

  //For different Player kinds
  int spiderWebs, fireBalls, stones;

  //for life
  int life;
  bool BcanGetDamage, red;
  sf::Clock playerClock, renderClock;
  //for finishing the level
  bool key;
public:
  PhysicsComponent physCom;
  Player();
  ~Player();
  void update(sf::Time deltaTime);
  AnimatedSprite& getSprite();
  sf::Sprite& getHud();
  sf::Vector2f getPos();
  void setPosition(sf::Vector2f nP);
  void pickupKey();
  void kill();
  int getLife();
  void setLife(int l);
  bool canGetDamage();
};
