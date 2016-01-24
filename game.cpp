#include "game.h"

Game::Game()
{
  level1.setPlayerPointer(player);
}

Game::~Game()
{

}

void Game::update()
{
  sf::Time temp = gameTimer.restart();
  level1.update(temp);
  player.update(temp);
}

void Game::render(sf::RenderWindow& window)
{
  level1.draw(window);
  if(player.isShot())
  {
    window.draw(player.getProjectile());
  }
  window.draw(player.getSprite());
}
