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
}

PhysicsComponent::~PhysicsComponent()
{
  if(settings.is_open())
    settings.close();
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
  if(!inAir && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    velocity.y -= jumpHeight;
    inAir = true;
  }
  else if(newPos.y + velocity.y + grav + 135 <= 700)
  {
    velocity.y += grav;
    inAir = true;
  }
  else
  {
    velocity.y = 0;
    inAir = false;
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
