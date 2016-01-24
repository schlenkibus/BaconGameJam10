#include "flyingBook.h"

flyingBook::flyingBook() : Enemy()
{
  enemyResources.loadFromFileAndStore("book.png", "book_idle", "textures");
  idle.setSpriteSheet(enemyResources.getTextureFromMap("book_idle"));
  idle.addFrame(sf::IntRect(0, 0, 112, 80));
  sprite.setAnimation(idle);
  sprite.setPosition(rand() % 400 + 300, rand() % 100 + 550);
  direction.x = 0; direction.y = 0;
  addWaypoint();
}

flyingBook::~flyingBook()
{

}

void flyingBook::kill()
{
  dead = true;
}

void flyingBook::addWaypoint()
{
  if(sprite.getGlobalBounds().left <= 500)
  {
    waypoint = sf::Vector2f(rand() % 50 + 900, rand() % 100 + 500);
  }
  else
  {
    waypoint = sf::Vector2f(rand() % 50 + 100, rand() % 90 + 550);
  }
  direction = normalize(waypoint, sprite.getPosition());
}

void flyingBook::update(sf::Time deltaTime)
{
  if(!dead)
  {
    //Waypoint system
    sprite.update(deltaTime);

    sprite.move(direction * 0.003f);

    if(sprite.getGlobalBounds().left <= 20 || sprite.getGlobalBounds().left >= 900
      || sprite.getGlobalBounds().top <= 300 || sprite.getGlobalBounds().top >= 600)
      addWaypoint();
    }
    else
    {
      sprite.update(deltaTime);
      if(sprite.getGlobalBounds().top <= 700)
        sprite.move(0, 1);
    }
}

sf::Vector2f flyingBook::getPos()
{
  return sprite.getPosition();
}
