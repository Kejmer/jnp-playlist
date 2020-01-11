#ifndef MOVIE_H
#define MOVIE_H

#include "Playable.h"

class Movie : public Media
{
  void play() const override;
};

#endif /* MOVIE_H */