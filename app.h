#include "SFML/Graphics.hpp"
#include "splash.h"
#include "background.h"
#include "resources.h"
#include "menu.h"
#include <iostream>
#include "Animation.h"
#include "AnimatedSprite.h"
#include "game.h"

#pragma once

class App
{
public:
	enum gameState {splash, menu, game, outro};
	
private:
	//FPS
	sf::Text fpstext;
	sf::Font font;

	Menu mainMenu;
	Game gameG;
	Resources re; //Menu and splash resources
	sf::RenderWindow * m_window;
	gameState currentState;
	Splash splashScreen;
	Background backG;
	sf::Clock menuClock, clockLogic;
	sf::Time accumulator, ups;
public:
	App(sf::RenderWindow &window);
	void startGame();
	void exitGame();
	void update();
};
