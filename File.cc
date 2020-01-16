#include "File.h"
#include <iostream>

File::File(std::string s)
{
  // this->media = new Media(content);
}

File::~File()
{
  std::cout << "Czesc jestem destruktorem FILE\n";
  // delete this->media;
}

// Media *File::getMedia()
// {
//   return this->media;
// }