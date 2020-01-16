#ifndef ENCRIPTION_H
#define ENCRIPTION_H

#include <string>

class ROT13
{
private:
  static const std::string TRANS_KEY;

  static char translate(char c);

public:
  static std::string encode(const std::string &msg);
};

#endif /* ENCRIPTION_H */