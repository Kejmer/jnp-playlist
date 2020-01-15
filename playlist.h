#ifndef PLAYER_H
#define PLAYER_H

#include "Playable.h"
#include "Playlist.h"
#include "File.h"

class Player
{
private:
    
public:
  //Fabryka w środku
  shared_ptr<Playable> openFile(File file) //error gdy błąd w treści, jakiś validate by się przydał

  shared_ptr<Playlist> createPlaylist(std::string name);
};
/*wskaźniki na struktury daje, czy potrzebny error na powtorke nazwy??*/
#endif /* PLAYER_H */
