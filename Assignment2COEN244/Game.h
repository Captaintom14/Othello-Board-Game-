//
// Created by Thomas Mejia on 2023-03-15.
//

#ifndef ASSIGNMENT2COEN244_GAME_H
#define ASSIGNMENT2COEN244_GAME_H
#include <iostream>
#include "Player.h"
#include "Board.h"
#include <fstream>
#include <string>

using namespace std;

class Game {

private :
    // necessary attributes
    string namePlayer1;
    string namePlayer2;
    Player player1;
    Player player2;
    Player* currentPlayer;
    bool playablePosition;
    void save();


public :
    Board board;
    int playerCol = 0 ;
    int playerRow = 0;
    void load();
    
Game(Player p1, Player p2) {

        player1 = p1;
        player2 = p2;
        currentPlayer = &player1;
    }

 //new method
    int choiceOffsetBoard(int choice){

        bool correctNumber = true;
        int choiceBoard = 0;

        while (correctNumber == true){
            try {

                cout <<"Please select a number between 1 and 4." << endl;
                cin >> choiceBoard;
                if (choiceBoard < 1 || choiceBoard > 4){
                    correctNumber = true;
                    throw 1;
                } else {
                    correctNumber = false;
                }

            } catch(int notGoodNumber){
                cout << "Please try again. Type between 1 and 4."<<endl;
                cout <<"***********************" << endl;
            }


        }




        return choiceBoard;
    }

//start method
   void start(){

        cout <<"Before we start this game, please choose an othello board." << endl;

        int choiceBoard = 0;
        int choiceOffSet = 0;
        bool rightBoard = true;
        while (rightBoard == true){
            try {

                cout << "1. An Offeset Starting Position." << endl;
                cout << "2. Four-by-Four Starting Position." << endl;
                cin >> choiceBoard;

                if (choiceBoard != 1 && choiceBoard != 2){
                    rightBoard = true;
                    throw 1;
                } else{
                    rightBoard = false;
                }

                if (choiceBoard == 1){

                    choiceOffSet = choiceOffsetBoard(choiceOffSet);

                    if (choiceOffSet == 1){

                        cout <<"You have chosen Board " << choiceOffSet << "." << endl;
                        cout << "Let's play Othello!" << endl;
                        board.drawBoard1();
                        play();
                        cout <<" " << endl;

                    }

                    if (choiceOffSet == 2){
                        cout <<"You have chosen Board " << choiceOffSet << "." << endl;
                        cout << "Let's play Othello!" << endl;
                        board.drawBoard2();
                        play();
                        cout <<" " << endl;

                    }

                    if (choiceOffSet == 3){
                        cout <<"You have chosen Board " << choiceOffSet << "." << endl;
                        cout << "Let's play Othello!" << endl;
                        board.drawBoard3();
                        play();
                        cout <<" " << endl;

                    }

                    if (choiceOffSet == 4){
                        cout <<"You have chosen Board " << choiceOffSet << "." << endl;
                        cout << "Let's play Othello!" << endl;
                        board.drawBoard4();
                        play();
                        cout <<" " << endl;

                    }


                }

                if (choiceBoard == 2){
                    cout << "You have chosen the Four-by-Four Starting Position Board. " << endl;
                    cout << "Let's play Othello!" << endl;
                    board.drawBoard5();
                    play();
                    cout <<" " << endl;

                }

            } catch(int notGoodNumber){
                cout << "Please try again. Type between 1 and 2."<<endl;
                cout <<"***********************" << endl;
            }

        }

    }


    int verificationCol (int playerCol){

        bool goodNumber = true;

        while (goodNumber == true){
            try {
                cin >> playerCol;
                if (playerCol <= 0 || playerCol >= 9){
                    goodNumber = true;
                    throw 1;
                } else {
                    goodNumber = false;
                }

            } catch (int wrongNumber){
                cout <<"Wrong number. Please insert a number between 1-8" << endl;
            }

        }


        return playerCol;
    }

 int verificationRow(int playerRow){

        bool goodNumber = true;

        while (goodNumber == true){
            try {
                cin >> playerRow;
                if (playerRow <= 0 || playerRow >= 9){
                    goodNumber = true;
                    throw 1;
                } else {
                    goodNumber = false;
                }

            } catch (int wrongNumber){
                cout <<"Wrong number. Please insert a number between 1-8" << endl;
            }

        }


        return playerRow;
    }


     void playerVerification(){

        bool position = true;
        char colourPlayer = currentPlayerColour();
        while (position == true){

            try{
                cout << "Your piece is " << currentPlayerColour() << endl;

                cout <<"To insert a piece, please insert a number for the column between 1-8" << endl ;
                playerCol = verificationCol(playerCol);
                cout << "Column: " << playerCol<< endl;
                playerCol -= 1;

                cout << "Please insert a number for the row between 1-8" << endl;
                playerRow = verificationRow(playerRow);
                cout << "Row: "<< playerRow << endl;
                playerRow -= 1;

                //this will show up what's the numbers in programming. This line will not show in the final product.
                cout << "col [" << playerCol << "] row [ " << playerRow << " ]" <<endl;

                //verifies if the player input is playable or not

                playablePosition = board.verificationBoardPositionPlayer(playerCol, playerRow);

                if (playablePosition != true){
                    position = true;
                    throw 1;
                } else {
                    position = false;
                    board.newPiecePositionBoard(playerCol,playerRow,colourPlayer);
                    board.flipPieces(playerCol,playerRow,colourPlayer);

                }

            } catch (int notGood){
                cout << "This place is unplaybale or taken. Please try again. "<<endl;
                cout <<"*******************************************************" << endl;
            }

        }




    }


     int optionMenu (int optionPlayer){

        bool goodNumber = true;
                while (goodNumber == true){

                    try {
                        cout <<"****************************************"<<endl;
                        cout <<"*     What would you like to do?       *"<<endl;
                        cout <<"*--------------------------------------*"<<endl;
                        cout <<"* 1. Make a move                       *"<<endl;
                        cout <<"* 2. Save the game                     *"<<endl;
                        cout <<"* 3. Concede the game                  *"<<endl;
                        cout <<"****************************************"<<endl;

                        cin >> optionPlayer;

                        if (optionPlayer == 0 || optionPlayer > 3){
                            goodNumber = true;
                            throw 1;
                        } else {
                            goodNumber = false;
                        }

                    } catch(int notGoodNumber){
                        cout <<"Please try again with the right number" << endl;
                        cout <<"**************************************" << endl;
                    }


                }



        return optionPlayer;
    }

 void play() {

     board.printBoard();
   //  bool win = false;
     bool concede = false;
     bool availableMoves = false;

     //do-while
     do {

         board.takeTurn(currentPlayer);
         int optionPlayer = optionMenu(optionPlayer);
         if (optionPlayer == 1) {
             playerVerification();
             board.printBoard();
             availableMoves = board.verifyAvailableMoves(availableMoves);
             if (availableMoves != true) {
                 cout << "There's no more moves left." << endl;
             } else {
                 cout << "There's more moves left." << endl;
             }
         }
         if (optionPlayer == 2) {

             if (currentPlayer == &player1) {
                 currentPlayer = &player2;
             } else {
                 currentPlayer = &player1;
             }
             save();

         }

         if (optionPlayer == 3) {
             concede = true;
         }

         if (currentPlayer == &player1) {
             currentPlayer = &player2;
         } else {
             currentPlayer = &player1;
         }

     } while ((availableMoves == true) && (concede == false));



    if (availableMoves == true){
        char winningPiece = board.countingPiece();
        if (winningPiece == 'B'){
          cout <<"*******************************************"<< endl;
          cout <<player1.getNamePlayer() << " wins! " << endl;
            cout << "Thank you for playing! " << endl;
        }
        if (winningPiece == 'W'){
            cout <<"*****************************************" << endl;
            cout << player2.getNamePlayer() << " wins!" << endl;
            cout << "Thank you for playing! " << endl;
        }

        if (winningPiece == 'T'){
            cout <<"*****************************************" << endl;
            cout <<"It's a tie!"<< endl;
            cout << "Thank you for playing! " << endl;
        }

    }

         if (concede == true) {
             cout <<"**************************************************" << endl;
             cout << currentPlayer->getNamePlayer() <<" wins! " <<  endl;
             cout << "Thank you for playing! " << endl;
         }

     }




     char currentPlayerColour() {
         return (currentPlayer == &player1) ? 'B' : 'W';
     }
};

#endif //ASSIGNMENT2COEN244_GAME_H


