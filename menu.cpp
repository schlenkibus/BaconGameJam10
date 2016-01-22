#include "menu.h"

Menu::Menu()
{
  rs.loadFromFileAndStore(std::string("background_sky.png"), std::string("sky"), std::string("textures"));
  backg.setTexture(rs.getTextureFromMap(std::string("sky")));
}

Menu::~Menu()
{
  rs.deleteAll();
}

void Menu::draw(sf::RenderWindow &window)
{
  window.draw(backg);
}
