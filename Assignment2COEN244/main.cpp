#include <iostream>
using namespace std;
#include "Player.h"
#include "Game.h"

int menu(int optionPlayer){

    bool correctNumber = true;
    while (correctNumber == true){
        try{
            cout <<"*********************************************"<<endl;
            cout <<"*      Welcome to the Othello game!         *"<<endl;
            cout <<"*********************************************"<<endl;
            cout <<"What would you like to do?\n"<< "Please press the numerical number shown here\n"<<"1. Start a new game! \n"<< "2. Load a game.\n"<< "3. Quit the game. \n" << endl;

            cin >> optionPlayer;
            if (optionPlayer > 3 ){
                correctNumber = true;
                throw 1;
            } else {
                correctNumber = false;
            }
        }

        catch (int error){
            cout << "Please try again with the correct number."<<endl;
            cout <<"***********************" << endl;
        }

    }

    if (optionPlayer == 3){
        cout <<"See you next time! "<< endl;
        exit(0);
    }

    return optionPlayer;

}



int main() {
    
    Player p1;
    Player p2;
    string namePlayer1;
    string namePlayer2;

    int choiceUser = menu(choiceUser);



    if (choiceUser == 1) {
        cout << "Please insert Player 1's name: " << endl;
        cin >>namePlayer1;

        cout << "Please insert Player 2's name: " << endl;
        cin >> namePlayer2;

        p1.setNamePlayer(namePlayer1);
        p2.setNamePlayer(namePlayer2);
        cout << "Player 1 is "<< p1.getNamePlayer()<<" and your pieces are black. (B)" << endl;
        cout << "Player 2 is " << p2.getNamePlayer()<<" and your pieces are white. (W)"<< endl;
        Game g(p1, p2);
        g.start();
    }

    if (choiceUser == 2){
        Game g(p1,p2);
        g.load();

    }

    if (choiceUser == 3){
        cout <<"See you next time! "<< endl;
        exit(0);
    }

return 0;

}
