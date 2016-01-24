#include "stone.h"

stonePickup::stonePickup()
{
  rs.loadFromFileAndStore("stonePick.png", "stone", "textures");
  sprite.setTexture(rs.getTextureFromMap("stone"), true);
}
