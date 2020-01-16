#ifndef PLAY_PLAYER_H
#define PLAY_PLAYER_H

#include "Playlist.h"

class Player
{
public:
    shared_ptr<Playlist> CreatePlaylist(string name);

};
#endif //PLAY_PLAYER_H
