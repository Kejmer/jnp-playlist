#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Playable.h"

class Playlist : public Playable
{
public:
  void play() const override;
};

#endif /* PLAYLIST_H */