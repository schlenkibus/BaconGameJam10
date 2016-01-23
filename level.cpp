#include "level.h"

libaryLevel::libaryLevel()
{
  levelData.open("json/level1.json", std::fstream::in);
  sf::Vector2f temp1, temp2, temp3, temp4;
  std::string line;
  levelData >> temp1.x >> temp1.y >> temp2.x >> temp2.y >> temp3.x >> temp3.y  >> temp4.x >> temp4.y;
  levelData.close();

  platform1.setPosition(temp1);
  platform2.setPosition(temp2);
  platform3.setPosition(temp3);
  platform4.setPosition(temp4);

  door.setPosition(sf::Vector2f(950, 525));

  libraryRS.loadFromFileAndStore("/backgrounds/blackWall.png", "libBack", "textures");
  libraryRS.loadFromFileAndStore("/platforms/platform2x1.png", "floorTile", "textures");
  libraryRS.loadFromFileAndStore("/platforms/platform1x1.png", "platform1x1", "textures");
  libraryRS.loadFromFileAndStore("/platforms/platform2x1_2.png", "platform2x1", "textures");
  Floor.setTexture(libraryRS.getTextureFromMap("floorTile"));
  Floor.setScale(5.74712644f, 1.f);
  Floor.setPosition(0, 675);

  platform1.setTexture(libraryRS.getTextureFromMap("platform1x1"));
  platform2.setTexture(libraryRS.getTextureFromMap("platform2x1"));
  platform3.setTexture(libraryRS.getTextureFromMap("platform2x1"));
  platform4.setTexture(libraryRS.getTextureFromMap("platform1x1"));

  backG.setTexture(libraryRS.getTextureFromMap("libBack"));
  backG.setPosition(0, 0);
}

void libaryLevel::update(sf::Time deltaTime)
{
  enemy1.update(deltaTime);
  enemy2.update(deltaTime);
  enemy3.update(deltaTime);
  door.update(deltaTime);
}

void libaryLevel::draw(sf::RenderWindow &window)
{
  window.draw(backG);
  window.draw(Floor);
  window.draw(platform1);
  window.draw(platform2);
  window.draw(platform3);
  window.draw(platform4);
  window.draw(door.getSprite());
  window.draw(door.getTriggerSprite());
  window.draw(enemy1.getSprite());
  window.draw(enemy2.getSprite());
  window.draw(enemy3.getSprite());
}
