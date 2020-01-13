#ifndef ENCRIPTION_H
#define ENCRIPTION_H

class ROT13
{
private:

  static const std::string  input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  static const std::string output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
  static char translate(char c);

public:
  static std::string encode(const std::string &msg) const;
}

#endif /* ENCRIPTION_H */