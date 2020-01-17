#ifndef MEDIA_H
#define MEDIA_H

#include <vector>
#include "Playable.h"
#include "PlayerException.h"

class Media : public Playable
{
private:
  string mediaType;
  vector<std::string> metadata;
  string content;

  void displayMetadata() const;
  void displayContent() const;
  void displayType() const;

  static const string audioMeta[2];
  static const string videoMeta[2];

public:

  Media(string &content);

  void play() const;

};

#endif /* MEDIA_H */
