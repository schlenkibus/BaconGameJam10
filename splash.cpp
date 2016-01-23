#include "splash.h"

Splash::Splash()
{
	rs.loadFromFileAndStore("splash.png", "splash", "textures");
	sprite.setTexture(rs.getTextureFromMap("splash"));
}

void Splash::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Splash::toggleMusic()
{
	if(mus.getStatus() == sf::Music::Playing)
		mus.stop();
	else
		mus.play();
}

void Splash::playMusic()
{
	if(mus.getStatus() != sf::Music::Playing)
		mus.play();
}