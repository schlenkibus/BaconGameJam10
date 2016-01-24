#include "endTrigger.h"

wizzard::wizzard()
{
  rs.loadFromFileAndStore("cageWizzard.png", "final", "textures");
  cage.setTexture(rs.getTextureFromMap("final"));
  cage.setPosition(sf::Vector2f(600, 450));
}
