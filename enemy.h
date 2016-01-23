#include "AnimatedSprite.h"
#include "Animation.h"
#include "resources.h"
#include "SFML/Graphics.hpp"

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
  sf::Vector2f interpolate(const sf::Vector2f& pointA,
                           const sf::Vector2f& pointB,
                           float factor)
  {
    if(factor > 1.f)
    {
      factor = 1.f;
    }
    else if(factor < 0.f)
    {
      factor = 0.f;
    }

    return pointA + (pointB - pointA) * factor;
  };
};
