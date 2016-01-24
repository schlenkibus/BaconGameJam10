#include "bossKnife.h"

bossKnife::bossKnife()
{
  rs.loadFromFileAndStore("mobs/knifeBoss.png", "bossIdle", "textures");
  rs.loadFromFileAndStore("mobs/knifeBossHit.png", "bossHit", "textures");
  rs.loadFromFileAndStore("mobs/knifeBossDead.png", "bossDead", "textures");
  idle.setSpriteSheet(rs.getTextureFromMap("bossIdle"));
  stickied1.setSpriteSheet(rs.getTextureFromMap("bossHit"));
  idle.addFrame(sf::IntRect(27, 25, 196, 215));
  stickied1.addFrame(sf::IntRect(27, 25, 196, 215));
  sprite.setPosition(800, 500);
  sprite.setAnimation(idle);

  Animdead.setSpriteSheet(rs.getTextureFromMap("bossDead"));
  Animdead.addFrame(sf::IntRect(28, 24, 207, 215));

  dead = false;
  health = 30;
}

void bossKnife::update(sf::Time deltaTime)
{
  if(dead)
    return;

  if(health <= 10)
    dead = true;

  sprite.update(deltaTime);
}

void bossKnife::onHit()
{
  if(health < 10)
  {
    return;
  }
  health -= 10;
  if(health == 20)
  {
    sprite.setAnimation(stickied1);
  }
  if(health == 10)
  {
    sprite.setAnimation(Animdead);
  }
}
