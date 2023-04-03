//
// Created by Thomas Mejia on 2023-03-15.
//

#ifndef ASSIGNMENT2COEN244_POSITION_H
#define ASSIGNMENT2COEN244_POSITION_H


class Position {

private :
    char piece;

public :
    static const char EMPTY = ' ';
    static const char BLACK = 'B';
    static const char WHITE = 'W';
    
bool virtual canPlay() {
     return true;
 }

};


#endif //ASSIGNMENT2COEN244_POSITION_H
