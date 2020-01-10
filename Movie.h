#ifndef MOVIE_H
#define MOVIE_H

#include "Playable.h"

class Movie : public Playable
{
  void play() override;
};

#endif /* MOVIE_H */