#ifndef MEDIA_H
#define MEDIA_H

#include <list>
#include <regex>
#include <vector>
#include "Playable.h"
#include "PlayerException.h"



class Media : public Playable
{
private:

  static const std::regex audioPattern;
  static const std::regex videoPattern;

  std::string play_contents;

public:

  Media(std::string &content);
  ~Media() = default;

  void play() const override;

};

#endif /* MEDIA_H */
