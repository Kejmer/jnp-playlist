#include "File.h"
#include <iostream>

File::File(std::string &&s)
{
  this->media = std::make_shared<Media>(s);
}

File::~File()
{
  std::cout << "Czesc jestem destruktorem FILE\n";
  this->media.reset();
}

std::shared_ptr<Media> File::getMedia()

{
  std::cout << "Czesc jestem destruktorem FILE\n";
  // delete this->media;
}

// Media *File::getMedia()
// {
//   return this->media;
// }