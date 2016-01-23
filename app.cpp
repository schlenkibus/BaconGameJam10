#include "app.h"

App::App(sf::RenderWindow &window)
{
	accumulator = sf::Time::Zero;
	ups = sf::seconds(1.f / 60.f);
	m_window = &window;
	currentState = App::splash;
	menuClock.restart();
	font.loadFromFile("fonts/Aaargh/Aaargh.ttf");
}

void App::update()
{
	while(accumulator > ups)
	{
		accumulator -= ups;
		switch(currentState)
		{
			case App::splash:
				if(menuClock.getElapsedTime().asSeconds() >= 1.f)
				{
					currentState = App::game;
					menuClock.restart();
				}
			break;
			case App::menu:
				//Menu
			break;
			case App::game:
				gameG.update();
			break;
			default:
				currentState = App::splash;
			break;
		}
	}

	m_window->clear();
	if(currentState == App::splash)
		splashScreen.draw(*m_window);
	else if(currentState == App::menu)
		mainMenu.draw(*m_window);
	else if(currentState == App::game)
		gameG.render(*m_window);
	m_window->display();
	accumulator += clockLogic.restart();
}
