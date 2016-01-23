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
}

void Game::render(sf::RenderWindow& window)
{
  window.draw(player.getSprite());
}
