#include "flyingBook.h"

flyingBook::flyingBook() : Enemy()
{
  enemyResources.loadFromFileAndStore("book.png", "book_idle", "textures");
  idle.setSpriteSheet(enemyResources.getTextureFromMap("book_idle"));
  idle.addFrame(sf::IntRect(0, 0, 112, 80));
  sprite.setAnimation(idle);
  sprite.setPosition(300, 400);
}

void flyingBook::update(sf::Time deltaTime)
{
    //Waypoint system

}
