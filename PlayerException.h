#ifndef PLAYER_EXCEPTION_H
#define PLAYER_EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

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

    virtual const string getType() const = 0;

    const char * what() const throw()
    {
        string s = "WRONG METADATA FOR " + getType();
        char * c = new char[s.size()];
        copy(s.begin(), s.end(), c);
        return c;
    }
};

class BadMetadataMovieException : public BadMetadataAbstrException
{
    const string getType() const
    {
        return "video";
    }
};

class BadMetadataMusicException : public BadMetadataAbstrException
{
    const string getType() const
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

class DuplicateException : public PlayerException // czy to potrzebne???
{
    const char * what() const throw()
    {
        return "REQUESTED PLAYLIST ALREADY EXISTS";
    }
};

class CycleException : public PlayerException
{
    const char * what () const throw()
    {
        return "CYCLE FOUND";
    }
};

class MemoryException : public PlayerException
{
    const char * what () const throw()
    {
        return "NOT ENOUGH MEMORY";
    }
};

class RangeException : public PlayerException
{
    const char * what () const throw()
    {
        return "OUT OF RANGE";
    }
};

class ShuffleException : public PlayerException
{
    const char * what () const throw()
    {
        return "SHUFFLE FAILED";
    }
};
#endif /* PLAYER_EXCEPTION_H */