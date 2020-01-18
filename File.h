#ifndef PLAYLIST_FILE_H
#define PLAYLIST_FILE_H

#include "Media.h"
#include <memory>


class File
{
private:
  shared_ptr<Media> media;

public:
  File(string &&s);

  ~File();

  shared_ptr<Media> getMedia();
};

#endif /* PLAYLIST_FILE_H */
