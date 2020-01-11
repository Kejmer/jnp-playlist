#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Playable.h"

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

#endif /* PLAYLIST_H */