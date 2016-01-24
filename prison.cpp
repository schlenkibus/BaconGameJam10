#include "prison.h"

prison::prison()
{
  rs.loadFromFileAndStore("backgrounds/prison.png", "back", "textures");
  rs.loadFromFileAndStore("final_screen.png", "final", "textures");
  backG.setTexture(rs.getTextureFromMap("back"));
}

void prison::update(sf::Time deltaTime)
{
  if(p_player->getPhysCom().getPos().x >= 600)
  {
    wiz.cage.setColor(sf::Color::Transparent);
    backG.setTexture(rs.getTextureFromMap("final"));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
      exit(99);
    }
  }
}

void prison::draw(sf::RenderWindow &window)
{
  window.draw(backG);
  window.draw(wiz.cage);
  window.draw(wiz.speech);
}

void prison::setPlayerPointer(Player &p)
{
  p_player = &p;
}
