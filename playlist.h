#ifndef PLAYER_H
#define PLAYER_H

#include "Playlist.h"
#include "File.h"

class Player
{
public:

    std::shared_ptr<Playable> openFile(File file); //error gdy błąd w treści, jakiś validate by się przydał

    std::shared_ptr<Playlist> createPlaylist(std::string name);
};

#endif /* PLAYER_H */
