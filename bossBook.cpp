#include "bossBook.h"

bossBook::bossBook()
{
  rs.loadFromFileAndStore("bossBook.png", "bossIdle", "textures");
  idle.setSpriteSheet(rs.getTextureFromMap("bossIdle"));
  idle.addFrame(sf::IntRect(35, 20, 172, 200));

  dead.setSpriteSheet(rs.getTextureFromMap("bossIdle"));
  dead.addFrame(sf::IntRect(0, 0, 140, 14));

  sprite.setAnimation(idle);
  sprite.setPosition(800, 480);
  health = 100; red = false;
  canBeHit = true; alive = true;
}

void bossBook::onHit()
{
  if(canBeHit == true)
  {
    health -= 20;
    canBeHit = false;
    bossClock.restart();
  }
}

void bossBook::update(sf::Time deltaTime)
{
  if(health <= 0)
  {
    sprite.setAnimation(dead);
    alive = false;
    //sprite.setPosition(800, 680);
  }
  sprite.update(deltaTime);
  if(renderClock.getElapsedTime().asSeconds() >= 0.05f && canBeHit == false)
  {
    if(red)
    {
      sprite.setColor(sf::Color::White);
      red = false;
    }
    else
    {
      sprite.setColor(sf::Color::Red);
      red = true;
    }
    renderClock.restart();
  }
  if(bossClock.getElapsedTime().asSeconds() >= 1.f && canBeHit == false)
  {
    canBeHit = true;
    bossClock.restart();
    sprite.setColor(sf::Color::White);
  }
}
