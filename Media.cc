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
  for (unsigned i = 0; i < this->metadata.size(); i++) {
    if (i > 0) std::cout << ", ";
    std::cout << this->metadata[i];
  }
  std::cout << "]";
}

void Media::displayContent() const
{
  std::cout << this->content;
}

Media::Media(std::string &content) {
  mediaType = content;
  metadata.push_back(content);
  this->content = content;
}