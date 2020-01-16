#include "Media.h"

#include <iostream>

void Media::play() const
{
  displayType();
  displayMetadata();
  displayContent();
}

void Media::displayMetadata() const
{
  std::cout << "[";
  for (unsigned i = 0; i < metadata.size(); i++) {
    if (i > 0) std::cout << ", ";
    std::cout << metadata[i];
  }
  std::cout << "]";
}

void Media::displayContent() const
{
  std::cout << content;
}

void Media::displayType() const
{
  std::cout << mediaType;
}

Media::Media(std::string &content)
{
  mediaType = "ASSD";
  this->content = "ASXX";
  std::cout << "TEST1 " << content << std::endl;
  std::cout << "TEST2 " << this->content << std::endl;

  // mediaType = content;
  // metadata.push_back(content);
  // this->content = content;
}