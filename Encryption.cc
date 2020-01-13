#include "Encription.h"

char ROT13::translate(char c)
{
  if ("A" <= c && c <= "Z")
    return this->output[int(c-"A")];
  if ("a" <= c && c <= "z") {
    int position = "Z" - "A" + 1 + c - "a";
    return this->output[position];
  }
  return c;
}

std::string ROT13::encode(const std::string &msg)
{
  std::string res = "";
  for (char c : msg) {
    res += translate(c);
  }
  return res;
}