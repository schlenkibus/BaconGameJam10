#include "spiderWeb.h"

WebPickup::WebPickup()
{
  rsPickup.loadFromFileAndStore("spiderWeb.png", "spiderWeb", "textures");
  sprite.setTexture(rsPickup.getTextureFromMap("spiderWeb"));
}

sf::Sprite& WebPickup::getSprite()
{
  return sprite;
}
