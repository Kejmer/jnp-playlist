#ifndef PLAYLIST_FILE_H
#define PLAYLIST_FILE_H

#include "Media.h"
#include <memory>


class File
{
private:
  std::shared_ptr<Media> media;
  void create_media(std::string &s);

public:
  File(std::string &&s);
  File(std::string s);
  File(const char * s);

  ~File() = default;

  std::shared_ptr<Media> getMedia();
};

#endif /* PLAYLIST_FILE_H */
