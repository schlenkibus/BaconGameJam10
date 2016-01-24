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

  libraryRS.loadFromFileAndStore("/backgrounds/library.png", "libBack", "textures");
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

  fire1.getSprite().setPosition(600, 600);
  fire2.getSprite().setPosition(400, 600);
  fire3.getSprite().setPosition(500, 600);

  eFR1.height = enemy1.getSprite().getGlobalBounds().height - 10;
  eFR1.width = enemy1.getSprite().getGlobalBounds().width - 10;
  eFR2.height = enemy1.getSprite().getGlobalBounds().height - 10;
  eFR2.width = enemy1.getSprite().getGlobalBounds().width - 10;
  eFR3.height = enemy1.getSprite().getGlobalBounds().height - 10;
  eFR3.width = enemy1.getSprite().getGlobalBounds().width - 10;
}

void libaryLevel::update(sf::Time deltaTime)
{
  enemy1.update(deltaTime);
  enemy2.update(deltaTime);
  enemy3.update(deltaTime);

  fire1.update(deltaTime);
  fire2.update(deltaTime);
  fire3.update(deltaTime);

  boss.update(deltaTime);

  if(p_player->getSprite().getGlobalBounds().intersects(boss.sprite.getGlobalBounds()))
  {
    if(p_player->isFlame)
    {
      boss.onHit();
    }
    else
    {
      if(p_player->canGetDamage() && boss.alive)
        p_player->setLife(p_player->getLife() - 50);
      if(p_player->getLife() <= 0)
        p_player->kill();
    }
  }
/*
  t1.width = eFR1.width; t1.height = eFR1.height;
  t2.width = eFR2.width; t2.height = eFR2.height;
  t3.width = eFR3.width; t3.height = eFR3.height;
  */
  //Collisons
  if(p_player->getSprite().getGlobalBounds().intersects(enemy1.getSprite().getGlobalBounds())
  || p_player->getSprite().getGlobalBounds().intersects(enemy2.getSprite().getGlobalBounds())
  || p_player->getSprite().getGlobalBounds().intersects(enemy3.getSprite().getGlobalBounds()))
  {
    if(p_player->isFlame)
    {
      if(p_player->getSprite().getGlobalBounds().intersects(enemy1.getSprite().getGlobalBounds()))
      {
        enemy1.kill();
      }
      if(p_player->getSprite().getGlobalBounds().intersects(enemy2.getSprite().getGlobalBounds()))
      {
        enemy2.kill();
      }
      if(p_player->getSprite().getGlobalBounds().intersects(enemy3.getSprite().getGlobalBounds()))
      {
        enemy3.kill();
      }
    }
    else
    {
      if(p_player->canGetDamage())
        p_player->setLife(p_player->getLife() - 10);
      if(p_player->getLife() <= 0)
        p_player->kill();
    }
  }

  //Level Change
  if(p_player->getPos().x >= 950)
  {
      p_player->currentLevel = 2;
      p_player->getPhysCom().setPosition(sf::Vector2f(100, 200));
      p_player->getPhysCom().setCurrentLevel(2);
  }
  //Fire
  if(p_player->getSprite().getGlobalBounds().intersects(fire1.getSprite().getGlobalBounds()))
  {
    p_player->pickupFire();
    fire1.getSprite().setPosition(-200.f, -200.f);
  }
  if(p_player->getSprite().getGlobalBounds().intersects(fire2.getSprite().getGlobalBounds()))
  {
    p_player->pickupFire();
    fire2.getSprite().setPosition(-200.f, -200.f);
  }
  if(p_player->getSprite().getGlobalBounds().intersects(fire3.getSprite().getGlobalBounds()))
  {
    p_player->pickupFire();
    fire3.getSprite().setPosition(-200.f, -200.f);
  }
}

void libaryLevel::draw(sf::RenderWindow &window)
{
  window.draw(backG);
  window.draw(Floor);
  window.draw(platform1);
  window.draw(platform2);
  window.draw(platform3);
  window.draw(platform4);

  window.draw(fire1.getSprite());
  window.draw(fire2.getSprite());
  window.draw(fire3.getSprite());
  window.draw(boss.sprite);
  window.draw(enemy1.getSprite());
  window.draw(enemy2.getSprite());
  window.draw(enemy3.getSprite());
}

void libaryLevel::setPlayerPointer(Player &p)
{
  p_player = &p;
}
