#ifndef PLAYER_H
#define PLAYER_H

#include "Playlist.h"
#include "File.h"

class Player
{
private:

public:

  shared_ptr<Playable> openFile(File file); //error gdy błąd w treści, jakiś validate by się przydał

  shared_ptr<Playlist> createPlaylist(string name);
};

#endif /* PLAYER_H */
