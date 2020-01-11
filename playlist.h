#ifndef PLAYER_H
#define PLAYER_H

#include <unordered_set>
#include "Playable.h"
#include "Playlist.h"
#include "File.h"

class Player
{
private:
  unordered_set<std::string> _playlists;

public:
  //Fabryka w środku
  Playable openFile(File file) //error gdy błąd w treści, jakiś validate by się przydał

  Playlist createPlaylist(std::string name); //error gdy się powtarza nazwa
};

#endif /* PLAYER_H */