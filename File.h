#ifndef PLAYLIST_FILE_H
#define PLAYLIST_FILE_H

#include "Media.h"
#include <memory>


class File
{
private:
    std::shared_ptr<Media> media;

public:
  File(std::string &&s);

  ~File();

    std::shared_ptr<Media> getMedia();
};

#endif /* PLAYLIST_FILE_H */
