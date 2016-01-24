#include "physicsComp.h"

PhysicsComponent::PhysicsComponent()
{
  speed = 5;
  acc = 3;
  negative_acc = 2;
  grav = 9;
  jumpHeight = 18;
  moving = false;
  settings.open("json/physics.json", std::fstream::in);
  std::string line;
  settings >> speed >> acc >> negative_acc >> grav >> jumpHeight;
  settings.close();
  inAir = false;

  loadLevelData();
}

PhysicsComponent::~PhysicsComponent()
{
  if(settings.is_open())
    settings.close();
  if(level1.is_open())
    level1.close();
}

sf::Vector2f PhysicsComponent::update(sf::Time deltaTime)
{
    ///////// Movement
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !moving)
  {
    velocity.x = -speed - acc;
    moving = true;
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !moving)
  {
    velocity.x = speed + acc;
    moving = true;
  }
  else if(moving == true || velocity.x != 0)
  {
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) &&
      !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if(velocity.x > 0)
        {
          velocity.x -= negative_acc;
        }
        else if(velocity.x < 0)
        {
          velocity.x += negative_acc;
        }
        if(velocity.x > -0.5f && velocity.x < 0.5f)
        {
          velocity.x = 0;
        }
        moving = false;
    }
  }
  //Y-Axis

  if(checkOnPlatform() == true)
  {
    inAir = false;
  }
  if(!inAir && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    velocity.y -= jumpHeight;
    inAir = true;
  }

  if(inAir)
  {
    newPos.y += velocity.y;
  }
  if(moving)
  {
    newPos.x += velocity.x;
  }

  return newPos;
}

void PhysicsComponent::setOnGroundFlag(bool onGround)
{
  inAir == !onGround;
}

void PhysicsComponent::setPosition(sf::Vector2f pos)
{
  newPos = pos;
}

sf::Vector2f PhysicsComponent::getPos()
{
  return newPos;
}

bool PhysicsComponent::checkOnPlatform()
{
  //Lee
  if(newPos.x >= l1p1.x && newPos.x <= l1p1.x + 85
      && newPos.y >= 620 && newPos.y <= 650)
  {
    velocity.y = 0;
    inAir = false;
    return true;
  }
  else if(newPos.x >= l1p2.x && newPos.x <= l1p2.x + 173
      && newPos.y >= 470 && newPos.y <= 500)
  {
    velocity.y = 0;
    inAir = false;
    return true;
  }
  else if(newPos.x >= l1p3.x && newPos.x <= l1p3.x + 173
      && newPos.y >= 320 && newPos.y <= 350)
  {
    velocity.y = 0;
    inAir = false;
    return true;
  }
  else if(newPos.x >= l1p4.x && newPos.x <= l1p4.x + 85
      && newPos.y >= 180 && newPos.y <= 200)
  {
    velocity.y = 0;
    inAir = false;
    return true;
  }
  else if(newPos.y + velocity.y + grav >= 700)
  {
    velocity.y = 0;
    inAir = false;
    return true;
  }
  else
  {
    velocity.y += grav;
    inAir = true;
    return false;
  }
}



void PhysicsComponent::loadLevelData()
{
  level1.open("json/level1.json", std::fstream::in);
  std::string line;
  level1 >> l1p1.x >> l1p1.y >> l1p2.x >> l1p2.y >> l1p3.x >> l1p3.y  >> l1p4.x >> l1p4.y;
  level1.close();
}

bool PhysicsComponent::isMoving()
{
  return moving;
}

float PhysicsComponent::getVelo()
{
  return velocity.x;
}
