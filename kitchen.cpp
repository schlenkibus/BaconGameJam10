#include "kitchen.h"

kitchen::kitchen()
{
  levelData.open("json/level2.json", std::fstream::in);
  sf::Vector2f temp1, temp2, temp3;
  std::string line;
  levelData >> temp1.x >> temp1.y >> temp2.x >> temp2.y >> temp3.x >> temp3.y;
  levelData.close();

  platform1.setPosition(temp1);
  platform2.setPosition(temp2);
  platform3.setPosition(temp3);

  rs.loadFromFileAndStore("/backgrounds/blackWall.png", "kitchenB", "textures");
  rs.loadFromFileAndStore("/platforms/platform2x1.png", "floor", "textures");
  rs.loadFromFileAndStore("/platforms/platform1x1.png", "platform1x1", "textures");
  rs.loadFromFileAndStore("/platforms/platform2x1_2.png", "platform2x1", "textures");

  Floor.setTexture(rs.getTextureFromMap("floor"));
  Floor.setScale(5.74712644f, 1.f);
  Floor.setPosition(0, 675);

  platform1.setTexture(rs.getTextureFromMap("platform1x1"));
  platform2.setTexture(rs.getTextureFromMap("platform2x1"));
  platform3.setTexture(rs.getTextureFromMap("platform2x1"));

  backG.setTexture(rs.getTextureFromMap("kitchenB"));
  backG.setPosition(0, 0);

  pickup1.getSprite().setPosition(100, 200);
  pickup2.getSprite().setPosition(300, 200);
  pickup3.getSprite().setPosition(400, 200);

  //TODO
}

void kitchen::update(sf::Time deltaTime)
{
    enemy1.update(deltaTime);
    enemy2.update(deltaTime);
    enemy3.update(deltaTime);

    boss.update(deltaTime);

    if(p_player->getSprite().getGlobalBounds().intersects(pickup1.getSprite().getGlobalBounds()))
    {
      p_player->pickupSpider();
      pickup1.getSprite().setPosition(-200.f, -200.f);
    }
    if(p_player->getSprite().getGlobalBounds().intersects(pickup2.getSprite().getGlobalBounds()))
    {
      p_player->pickupSpider();
      pickup2.getSprite().setPosition(-200.f, -200.f);
    }
    if(p_player->getSprite().getGlobalBounds().intersects(pickup3.getSprite().getGlobalBounds()))
    {
      p_player->pickupSpider();
      pickup3.getSprite().setPosition(-200.f, -200.f);
    }

    if(p_player->getProjectile().getGlobalBounds().intersects(boss.sprite.getGlobalBounds()))
    {
      boss.onHit();
      p_player->destroyProjectile();
    }

    if(p_player->getPos().x >= 950)
    {
        p_player->currentLevel = 3;
        p_player->getPhysCom().setPosition(sf::Vector2f(100, 200));
        p_player->getPhysCom().setCurrentLevel(3);
    }
  //Update
    if(p_player->getProjectile().getGlobalBounds().intersects(enemy1.getSprite().getGlobalBounds()))
    {
      enemy1.kill();
      p_player->destroyProjectile();
    }
    else if(p_player->getProjectile().getGlobalBounds().intersects(enemy2.getSprite().getGlobalBounds()))
    {
      enemy2.kill();
      p_player->destroyProjectile();
    }
    else if(p_player->getProjectile().getGlobalBounds().intersects(enemy3.getSprite().getGlobalBounds()))
    {
      enemy3.kill();
      p_player->destroyProjectile();
    }
}

void kitchen::draw(sf::RenderWindow &window)
{
  window.draw(backG);
  window.draw(Floor);
  window.draw(platform1);
  window.draw(platform2);
  window.draw(platform3);
  window.draw(pickup1.getSprite());
  window.draw(pickup2.getSprite());
  window.draw(pickup3.getSprite());
  window.draw(boss.sprite);
  window.draw(enemy1.getSprite());
  window.draw(enemy2.getSprite());
  window.draw(enemy3.getSprite());
}

void kitchen::setPlayerPointer(Player& p)
{
  p_player = &p;
}
