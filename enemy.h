#include "AnimatedSprite.h"
#include "Animation.h"
#include "resources.h"
#include "SFML/Graphics.hpp"
#include <math.h>

#pragma once

class Enemy
{
public:
  AnimatedSprite sprite;
  Animation idle;
  float health;
  Resources enemyResources;
  sf::Vector2f waypoint;
  Enemy();
  ~Enemy();
  void update(sf::Time deltaTime);
  int attackPlayer();
  AnimatedSprite& getSprite();
  void render(sf::RenderWindow& window);
  void setWayPoint(sf::Vector2f pos);
  float distance(sf::Vector2f p1, sf::Vector2f p2) {
    float xb = p2.x - p1.x;
    float yb = p2.y - p1.y;
    return sqrt((xb * xb) + (yb * yb));
  };
  sf::Vector2f normalize(sf::Vector2f p1, sf::Vector2f p2)
  {
    sf::Vector2f temp;
    temp.x = p1.x - p2.x;
    temp.y = p1.y - p2.y;
    return temp;
  };
};
