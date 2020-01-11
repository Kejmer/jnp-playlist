#include "MediaFactory.h"

MediaFactory::createMovie(std::string)
{
  return new Movie(std::string);
}

MediaFactory::createMusic(std::string)
{
  return new Music(std::string);
}