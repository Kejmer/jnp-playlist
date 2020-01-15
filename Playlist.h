#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Playable.h"
#include <memory>
#include <vector>
#include <deque>

class Playlist : public Playable
{
private:
    
    std::vector<shared_ptr<Playlist>> childs; // playlisty ktore sa w elems
        
    std::deque<shared_ptr<Playable>> elems; // to odtwarzamy

    bool check(Playlist* playlist)
    // sprawdzamy czy z this dojdziemy do playlist po childs

public:
  void play() const override;

  void add(shared_ptr<Playable>);

  void add(shared_ptr<Playable>, size_t position); //rzucamy wyjątek gdy za daleko chcemy wrzucić (?) do ustalenia

  void remove(); //rzucamy wyjątek gdy puste??

  void remove(size_t position); //rzucamy wyjątek gdy nie ma tej pozycji

  // void setMode(mode); //rzucamy wyjątek gdy zły tryb
};

#endif /* PLAYLIST_H */
