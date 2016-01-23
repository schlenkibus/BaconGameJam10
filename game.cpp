#include "game.h"

Game::Game()
{
}

Game::~Game()
{

}

void Game::update()
{
  player.update(gameTimer.restart());
  enemy1.update(gameTimer.restart());
}

void Game::render(sf::RenderWindow& window)
{
  window.draw(player.getSprite());
  window.draw(enemy1.getSprite());
}
