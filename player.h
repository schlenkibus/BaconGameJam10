#pragma once

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "AnimatedSprite.h"
#include <iostream>
#include "resources.h"
#include "physicsComp.h"

class Player
{
private:
  Resources playerResource;
  AnimatedSprite playerRender;
  Animation idleAnim, actionNone, actionHammer, actionFire, actionSpider;
  enum playerAnim {idle, jump, moveLeft, moveRight};
  enum playerAction {none, spider, fire, hammer};
  playerAction currentAction;
  sf::Vector2f pos;

  sf::Sprite projectile;
  bool projectileShot;

  //Movement!
  enum direction {facingLeft, facingRight};
  direction playerDirection;
  direction projectileDirection;

  //For different Player kinds
  int spiderWebs, fireBalls, stones;

  //Actionhanfling
  bool actionPlaying;
  sf::Clock actionClock;
  //for life
  int life;
  bool BcanGetDamage, red, gotDamage;
  sf::Clock playerClock, renderClock;

  void setAction();
public:
  int currentLevel;

  PhysicsComponent physCom;
  Player();
  ~Player();
  void update(sf::Time deltaTime);
  AnimatedSprite& getSprite();
  sf::Vector2f getPos();
  void setPosition(sf::Vector2f nP);
  void pickupKey();
  void kill();
  int getLife();
  void setLife(int l);
  bool canGetDamage();
  void doAction();
  //These also update the GUI and avaiable Actions
  void pickupSpider();
  void pickupFire();
  void pickupStone();
  bool isActionPlaying();
  sf::Sprite& getProjectile();
  bool isShot();
  void destroyProjectile();
  bool isFlame;
  PhysicsComponent& getPhysCom();
};
