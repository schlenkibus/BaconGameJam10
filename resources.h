#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include <map>

#pragma once

typedef std::map<std::string, sf::Texture> textureMap;
typedef std::map<std::string, sf::SoundBuffer> soundBufferMap;
typedef std::map<std::string, sf::Sound> soundPlayerMap;
typedef std::map<std::string, sf::Music> musicMap;
typedef std::map<std::string, sf::Font> fontMap;

class Resources
{
private:
  textureMap textures;
  soundBufferMap sounds;
  musicMap music;
  fontMap fonts;

  short convertMapToNumber(std::string mapName); // 0 Tex, 1 Sounds, 2 SoundBuffer, 3 Music, 4 Fonts
public:
  Resources();
  ~Resources();
  void loadFromFileAndStore(std::string fileName, std::string indexName, std::string mapName);
  sf::Texture& getTextureFromMap(std::string indexName);
  sf::SoundBuffer& getSoundBufferFromMap(std::string indexName);
  sf::Music& getMusicFromMap(std::string indexName);
  sf::Font& getFontFromMap(std::string indexName);
  void deleteResource(std::string indexName, std::string mapName);
  void deleteAll();
};
