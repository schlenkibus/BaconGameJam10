#include "SFML/Graphics.hpp"
#include "splash.h"
#include "background.h"
#include "resources.h"
#include "menu.h"

#pragma once

class App
{
public:
	enum gameState {splash, menu, game};
private:
	Menu mainMenu;
	Resources re;
	sf::RenderWindow * m_window;
	gameState currentState;
	Splash splashScreen;
	Background backG;
	sf::Clock menuClock;
public:
	App(sf::RenderWindow &window);
	void startGame();
	void exitGame();
	void update();
};
