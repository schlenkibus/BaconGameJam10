#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

class PhysicsComponent
{
private:
  bool moving, inAir;
  float speed, acc, negative_acc, grav, jumpHeight, maxSpeed;
  sf::Vector2f newPos;
  sf::Vector2f velocity;
  sf::Vector2f l1p1, l1p2, l1p3, l1p4;
  sf::Vector2f l2p1, l2p2, l2p3;
//  sf::Vector2f l1p1, l1p2, l1p3, l1p4;
  std::fstream settings, level1, level2;
  void loadLevelData();
  int currentLevel;
public:
  PhysicsComponent();
  ~PhysicsComponent();
  sf::Vector2f update(sf::Time deltaTime);
  sf::Vector2f getPos();
  void setOnGroundFlag(bool onGround);
  void setPosition(sf::Vector2f pos);
  bool checkOnPlatform();
  bool isMoving();
  float getVelo();
  void setCurrentLevel(int i);
};
