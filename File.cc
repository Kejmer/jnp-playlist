#include "File.h"

File::File(string &&s)
{
  try {
    this->media = std::make_shared<Media>(s);
  } catch (...) {
    throw MemoryException();
  }
}

File::~File()
{
  this->media.reset();
}

shared_ptr<Media> File::getMedia()
{
  return this->media;
}
