#ifndef PLAYER_EXCEPTION_H
#define PLAYER_EXCEPTION_H

#include <exception>
#include <string>
#include <iostream>

class PlayerException : public std::exception
{
public:
    virtual const char * what() const throw() = 0; //nie jestem pewien czy tak
};

// //Błąd zgłaszany gdy wejście nie zaczyna się od "video|" lub "audio|"
// class UnsupportedTypeException : public PlayerException
// {
//     const char * what() const throw()
//     {
//         return "UNSUPPORTED MEDIA TYPE; ONLY video AND audio ALLOWED";
//     }
// };

//Brak odpowiadających metadanych w video i audio
class BadMetadataException : public PlayerException
{
private:
    std::string missingData;

public:
    const char * what() const throw()
    {
        std::string s = "WRONG METADATA FOR " + missingData;
        char * c = new char[s.size()];
        copy(s.begin(), s.end(), c);
        return c;
    }

    BadMetadataException(std::string str) : missingData(str) {}
};

//Nielegalne znaki w stringu
class CorruptionException : public PlayerException
{
public:
    const char * what() const throw()
    {
        return "FILE IS CORRUPTED – ILLEGAL CHARACTERS / UNSUPPORTED TYPE";
    }
};

class DuplicateException : public PlayerException // czy to potrzebne???
{
public:
    const char * what() const throw()
    {
        return "REQUESTED PLAYLIST ALREADY EXISTS";
    }
};

class CycleException : public PlayerException
{
public:
    const char * what () const throw()
    {
        return "CYCLE FOUND";
    }
};

class MemoryException : public PlayerException
{
public:
    const char * what () const throw()
    {
        return "NOT ENOUGH MEMORY";
    }
};

class RangeException : public PlayerException
{
public:
    const char * what () const throw()
    {
        return "OUT OF RANGE";
    }
};

class ShuffleException : public PlayerException
{
public:
    const char * what () const throw()
    {
        return "SHUFFLE FAILED";
    }
};
#endif /* PLAYER_EXCEPTION_H */
