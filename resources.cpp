#include "resources.h"
#include <iostream>

Resources::Resources()
{

}

Resources::~Resources()
{
  deleteAll();
}

short Resources::convertMapToNumber(std::string mapName)
{
  if(mapName == "textures")
    return 0;
  else if(mapName == "sounds")
    return 2;
  else if(mapName == "music")
    return 3;
  else if(mapName == "fonts")
    return 4;
}

sf::Texture& Resources::getTextureFromMap(std::string indexName)
{
  return textures.find(indexName)->second;
}

sf::SoundBuffer& Resources::getSoundBufferFromMap(std::string indexName)
{
  return sounds.find(indexName)->second;
}

sf::Music& Resources::getMusicFromMap(std::string indexName)
{
  return music.find(indexName)->second;
}

sf::Font& Resources::getFontFromMap(std::string indexName)
{
  return fonts.find(indexName)->second;
}

void Resources::loadFromFileAndStore(std::string fileName,
                                      std::string indexName,
                                      std::string mapName)
{
  std::string tempString;
  switch(convertMapToNumber(mapName))
  {
    case 0: //Tex
    {
      tempString = "art/";
      tempString += fileName;
      sf::Texture tempTex;
      tempTex.loadFromFile(tempString);
      textures.emplace(indexName, tempTex);
    }
    break;
    case 2: //soundBuffer
    {
      tempString = "sfx/";
      tempString += fileName;
      sf::SoundBuffer tempSnd;
      tempSnd.loadFromFile(tempString);
      sounds.emplace(indexName, tempSnd);
    }
    break;
    case 4: //fonts
    {
    /*  tempString = "fonts/";
      tempString += fileName;
      sf::Texture tempFont;
      tempFont.loadFromFile(tempString);
      fonts.emplace(indexName, tempFont);*/
    }
    break;
    default:
    {
      //TODO Error
    }
      return;
    break;
  }
  return;
}

void Resources::deleteAll()
{
  textures.clear();
  sounds.clear();
  music.clear();
  fonts.clear();
}
