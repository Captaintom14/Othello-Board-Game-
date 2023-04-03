//
// Created by Thomas Mejia on 2023-03-19.
//

#ifndef ASSIGNMENT2COEN244_UNPLAYABLEPOSITION_H
#define ASSIGNMENT2COEN244_UNPLAYABLEPOSITION_H
#include "Position.h"

class UnPlayablePosition : public Position{

public :
const char UNPLAYABLE = '*';
bool canPlay() override  {
     return false;
}

};


#endif //ASSIGNMENT2COEN244_UNPLAYABLEPOSITION_H
