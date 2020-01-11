#ifndef FILE_H
#define FILE_H

#include "Media.h"

class File
{
private:
  Media file; //geter zaprzyjaźniony z playerem

public:
  File(std::string str);
};

#endif /* FILE_H */