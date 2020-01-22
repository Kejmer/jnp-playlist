#include "File.h"

void File::create_media(std::string &s)
{
  try {
    this->media = std::make_shared<Media>(s);
  } catch (PlayerException &pe) {
      throw;
  } catch (...) {
      throw MemoryException();
  }
}

File::File(std::string s)
{
  create_media(s);
}

File::File(std::string &&s)
{
  create_media(s);
}

File::File(const char *s)
{
  std::string str = std::string(s);
  create_media(str);
}

std::shared_ptr<Media> File::getMedia()
{
  return this->media;
}
