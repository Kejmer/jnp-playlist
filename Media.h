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

protected:

  virtual void displayType() const = 0;

public:

  Media(std::string &content);

  void play() const;

};

#endif /* MEDIA_H */