#include "pot.h"

Pot::Pot() : Enemy()
{
  enemyResources.loadFromFileAndStore("potL.png", "pot_left", "textures");
  left.setSpriteSheet(enemyResources.getTextureFromMap("pot_left"));
  left.addFrame(sf::IntRect(5, 14, 88, 73));
  left.addFrame(sf::IntRect(112, 14, 72, 72));
  left.addFrame(sf::IntRect(195, 14, 81, 72));
  left.addFrame(sf::IntRect(289, 14, 72, 72));
  sprite.setAnimation(left);
  sprite.setPosition(rand() % 400 + 300, 600);
  tempWay = false;
  dead = false;
}

void Pot::kill()
{
  sprite.setPosition(-200, -200);
  dead = true;
}

void Pot::update(sf::Time deltaTime)
{
  if(dead)
  {
    return;
  }
  sprite.update(deltaTime);
  if(tempWay == true)
  {
    sprite.move(-3, 0);
  }
  else
  {
    sprite.move(3, 0);
  }
  addWaypoint();
}

void Pot::addWaypoint()
{
  if(sprite.getPosition().x >= 900)
  {
    tempWay = true;
    return;
  }
  else if(sprite.getPosition().x <= 50)
  {
    tempWay = false;
    return;
  }
  /**/
}
