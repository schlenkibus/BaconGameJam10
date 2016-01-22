#include "app.h"
#include <iostream>

App::App(sf::RenderWindow &window)
{
	m_window = &window;
	currentState = App::splash;
	menuClock.restart();
}

void App::update()
{
	m_window->clear();
	switch(currentState)
	{
		case App::splash:
			if(menuClock.getElapsedTime().asSeconds() >= 3.f)
			{
				currentState = App::menu;
				menuClock.restart();
			}
			splashScreen.draw(*m_window);
		break;
		case App::menu:
			mainMenu.draw(*m_window);
		break;
		case App::game:
		break;
		default:
			currentState = App::splash;
		break;
	}
	m_window->display();
}
