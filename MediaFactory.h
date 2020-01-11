#ifndef MEDIA_FACTORY_H
#define MEDIA_FACTORY_H

#include "Music.h"
#include "Movie.h"

class MediaFactory {
public:
  static Movie createMovie(std::string);
  static Music createMusic(std::string);
}

#endif /* MEDIA_FACTORY_H */