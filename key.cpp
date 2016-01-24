#include "key.h"

Key::Key()
{
  tex.loadFromFileAndStore("key.png", "key", "textres");
  sprite.setTexture(tex.getTextureFromMap("key"));
}

sf::Vector2f Key::getPos()
{
  return sprite.getPosition();
}

sf::Sprite& Key::getSprite()
{
  return sprite;
}

void Key::setPosition(sf::Vector2f p)
{
  sprite.setPosition(p);
}
