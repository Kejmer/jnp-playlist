#include "File.h"

File::File(string &&s)
{
  this->media = std::make_shared<Media>(s);
}

File::~File()
{
  cout << "Czesc jestem destruktorem FILE\n";
  this->media.reset();
}

shared_ptr<Media> File::getMedia()
{
  return this->media;
}
