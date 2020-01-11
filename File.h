#ifndef FILE_H
#define FILE_H

#include "Media.h"

class File
{
private:
  Media media;

public:
  File(std::string str);

  Media getMedia();
};

#endif /* FILE_H */