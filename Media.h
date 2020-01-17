#ifndef MEDIA_H
#define MEDIA_H

#include <vector>
#include <string>
#include "Playable.h"

class Media : public Playable
{
private:
  std::string mediaType;
  std::vector<std::string> metadata;
  std::string content;

  void displayMetadata() const;
  void displayContent() const;
  void displayType() const;

  static const std::string audioMeta[2];
  static const std::string videoMeta[2];

public:

  Media(std::string &content);

  void play() const;

};

#endif /* MEDIA_H */