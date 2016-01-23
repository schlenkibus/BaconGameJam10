#include "enemy.h"

//Interpolation


Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::update(sf::Time deltaTime)
{
  //Logic
  
}

void Enemy::render(sf::RenderWindow& window)
{
  window.draw(sprite);
}

void Enemy::setWayPoint(sf::Vector2f pos)
{
  waypoints.emplace_back(pos);
}

AnimatedSprite& Enemy::getSprite()
{
  return sprite;
}
