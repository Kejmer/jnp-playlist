#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <unordered_set>
#include "Playable.h"
#include "Playlist.h"
#include "File.h"

class Playlist : public Playable
{
private:
  //tu wskaźnik na klasę reprezentującą strukturkę czy co tam wymyśliłeś
  //tryb
public:
  void play() const override;

  void add(element);

  void add(element, position); //rzucamy wyjątek gdy za daleko chcemy wrzucić (?) do ustalenia

  void remove(); //rzucamy wyjątek gdy puste

  void remove(position); //rzucamy wyjątek gdy nie ma tej pozycji

  // void setMode(mode); //rzucamy wyjątek gdy zły tryb
};


class Player
{
private:
  unordered_set<std::string> _playlists;

public:
  //Fabryka w środku
  Playable openFile(File file) //error gdy błąd w treści, jakiś validate by się przydał

  Playlist createPlaylist(std::string name); //error gdy się powtarza nazwa
};

#endif /* PLAYLIST_H */