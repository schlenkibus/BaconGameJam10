#include "SFML/Graphics.hpp"
#include <iostream>
#include "app.h"

int main ()
{
	sf::RenderWindow window(sf::VideoMode(1000, 750), "SFML", sf::Style::Close);
	sf::Event event;

	App app(window);

	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		app.update();
	}
	return 0;
}
