#include "flyingBook.h"

flyingBook::flyingBook() : Enemy()
{
  enemyResources.loadFromFileAndStore("book.png", "book_idle", "textures");
  idle.setSpriteSheet(enemyResources.getTextureFromMap("book_idle"));
  idle.addFrame(sf::IntRect(0, 0, 112, 80));
  sprite.setAnimation(idle);
  sprite.setPosition(300, 400);
  direction.x = 0; direction.y = 0;
  addWaypoint(sf::Vector2f(100, 500));
}

flyingBook::~flyingBook()
{

}

void flyingBook::addWaypoint(sf::Vector2f pos)
{
  waypoint = pos;
  direction = interpolate(sf::Vector2f(pos.x, sprite.getGlobalBounds().left),
                          sf::Vector2f(pos.y, sprite.getGlobalBounds().top),
                          1.0f);
}

void flyingBook::update(sf::Time deltaTime)
{
    //Waypoint system
    sprite.update(deltaTime);
    sprite.move(direction.x * 0.01f, direction.y * 0.01f);
    direction = interpolate(sf::Vector2f(waypoint.x, sprite.getGlobalBounds().left),
                            sf::Vector2f(waypoint.y, sprite.getGlobalBounds().top),
                            2.0f);
    if(sprite.getGlobalBounds().left <= 10 || sprite.getGlobalBounds().left >= 990
      || sprite.getGlobalBounds().top <= 300 || sprite.getGlobalBounds().top >= 600)
      addWaypoint(sf::Vector2f(800, rand() % 100 + 500));
}
