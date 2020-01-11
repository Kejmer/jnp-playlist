#ifndef PLAYER_EXCEPTION_H
#define PLAYER_EXCEPTION_H

#include <exception>

class PlayerException : public exception
{
  virtual const char * what() const throw() = 0; //nie jestem pewien czy tak
};

//Błąd zgłaszany gdy wejście nie zaczyna się od "video|" lub "audio|"
class UnsupportedTypeException : public PlayerException
{
  const char * what() const throw()
  {
    return "UNSUPPORTED MEDIA TYPE; ONLY video AND audio ALLOWED";
  }
};

//Brak odpowiadających metadanych w video i audio
class BadMetadataAbstrException : public PlayerException
{
protected:

  virtual const std::string getType() const = 0;

public:

  const char * what() const override throw()
  {
    std::string s = "WRONG METADATA FOR " + getType();
    return s;
  }
};

class BadMetadataMovieException : public BadMetadataAbstrException
{
  const std::string getType() const
  {
    return "video";
  }
};

class BadMetadataMusicException : public BadMetadataAbstrException
{
  const std::string getType() const
  {
    return "audio";
  }
};

//Nielegalne znaki w stringu
class CorruptionException : public PlayerException
{
  const char * what() const throw()
  {
    return "FILE IS CORRUPTED – ILLEGAL CHARACTERS";
  }
};

#endif /* PLAYER_EXCEPTION_H */