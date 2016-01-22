#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "resources.h"

#pragma once

class Splash
{
private:
	Resources rs;
	sf::Sprite sprite;
	sf::Music mus;
public:
	void draw(sf::RenderWindow &window);
	Splash();
	void toggleMusic();
	void playMusic();
};
