#include "game.h"

Game::Game()
{
  level1.setPlayerPointer(player);
  level2.setPlayerPointer(player);
  level3.setPlayerPointer(player);
  aLevel = lvl1;
  player.getPhysCom().setCurrentLevel(1);
  player.currentLevel = 1;
  mus.openFromFile("music/bg.ogg");
  mus.play();
  mus.setLoop(true);
  mus.setVolume(0.5f);
}

Game::~Game()
{

}

void Game::update()
{
  sf::Time temp = gameTimer.restart();
  if(aLevel == lvl1)
    level1.update(temp);
  else if(aLevel == lvl2)
    level2.update(temp);
  else if(aLevel == lvl3)
    level3.update(temp);
  player.update(temp);
}

void Game::render(sf::RenderWindow& window)
{
  setLevel(player.currentLevel);
  if(aLevel == lvl1)
    level1.draw(window);
  else if(aLevel == lvl2)
    level2.draw(window);
  else if(aLevel == lvl3)
    level3.draw(window);
  if(player.isShot())
  {
    window.draw(player.getProjectile());
  }
  window.draw(player.getSprite());
}

void Game::setLevel(int i)
{
  if(i == 1)
    aLevel = lvl1;
  else if(i == 2)
    aLevel = lvl2;
  else if(i == 3)
    aLevel = lvl3;

  player.getPhysCom().setCurrentLevel(i);
}
