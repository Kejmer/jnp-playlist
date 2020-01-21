#include "Encryption.h"

const std::string ROT13::TRANS_KEY = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

char ROT13::translate(char c)
{
  if ('A' <= c && c <= 'Z')
    return TRANS_KEY[int(c-'A')];
  if ('a' <= c && c <= 'z') {
    int position = 26 + c - 'a';
    return TRANS_KEY[position];
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