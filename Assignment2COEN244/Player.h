//
// Created by Thomas Mejia on 2023-03-15.
//

#ifndef ASSIGNMENT2COEN244_PLAYER_H
#define ASSIGNMENT2COEN244_PLAYER_H

#include <string>
using namespace std;


class Player {
private :
    string namePlayer;
public :

 void setNamePlayer(string name){
    this -> namePlayer = name;
}

string getNamePlayer(){
    return namePlayer;
}

};


#endif //ASSIGNMENT2COEN244_PLAYER_H
