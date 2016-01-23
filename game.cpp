#include "game.h"

Game::Game()
{
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
  window.draw(player.getSprite());
}
