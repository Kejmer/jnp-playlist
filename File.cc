#include "File.h"

File::File(std::string &&s)
{
  try {
    this->media = std::make_shared<Media>(s);
  } catch (PlayerException &pe) {
      throw;
  } catch (...) {
      throw MemoryException();
  }
}

std::shared_ptr<Media> File::getMedia()
{
  return this->media;
}
