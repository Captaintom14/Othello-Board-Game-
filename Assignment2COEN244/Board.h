//
// Created by Thomas Mejia on 2023-03-15.
//

#ifndef ASSIGNMENT2COEN244_BOARD_H
#define ASSIGNMENT2COEN244_BOARD_H
#include "Position.h"
#include "UnPlayablePosition.h"
#include "Player.h"
#include <iostream>


using namespace std;

class Board {
private :

    int playerCol = 0;
    int playerRow = 0;
    int countWhite = 0;
    int countBlack = 0;

public:
    char othelloBoard[8][8];

    Position position;
    UnPlayablePosition unPlayablePosition;

    void drawBoard1(){

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8 ; ++j) {
                othelloBoard[i][j] = position.EMPTY;
            }
        }

        othelloBoard [2][2] = position.WHITE;
        othelloBoard [3][3] = position.WHITE;
        othelloBoard [2][3] = position.BLACK;
        othelloBoard [3][2] = position.BLACK;

        othelloBoard [2][7] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [3][7] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [4][7] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [5][7] = unPlayablePosition.UNPLAYABLE;


    }

    void drawBoard2(){

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8 ; ++j) {
                othelloBoard[i][j] = position.EMPTY;
            }
        }
        //          col row
        othelloBoard [2][4] = position.WHITE;
        othelloBoard [3][5] = position.WHITE;
        othelloBoard [3][4] = position.BLACK;
        othelloBoard [2][5] = position.BLACK;

        othelloBoard [2][0] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [3][0] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [4][0] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [5][0] = unPlayablePosition.UNPLAYABLE;


    }

    void drawBoard3(){

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8 ; ++j) {
                othelloBoard[i][j] = position.EMPTY;
            }
        }
        //          col row
        othelloBoard [4][2] = position.WHITE;
        othelloBoard [5][3] = position.WHITE;
        othelloBoard [5][2] = position.BLACK;
        othelloBoard [4][3] = position.BLACK;


        othelloBoard [4][7] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [5][7] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [6][7] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [7][7] = unPlayablePosition.UNPLAYABLE;
    }

    void drawBoard4(){

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8 ; ++j) {
                othelloBoard[i][j] = position.EMPTY;
            }
        }
        //          col row
        othelloBoard [4][4] = position.WHITE;
        othelloBoard [5][5] = position.WHITE;
        othelloBoard [4][5] = position.BLACK;
        othelloBoard [5][4] = position.BLACK;

        othelloBoard [4][0] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [5][0] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [6][0] = unPlayablePosition.UNPLAYABLE;
        othelloBoard [7][0] = unPlayablePosition.UNPLAYABLE;

    }

    void drawBoard5(){

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8 ; ++j) {
                othelloBoard[i][j] = position.EMPTY;
            }
        }
        //          col row
        //up white pieces
        othelloBoard [2][2] = position.WHITE;
        othelloBoard [2][3] = position.WHITE;
        othelloBoard [3][2] = position.WHITE;
        othelloBoard [3][3] = position.WHITE;

        //down white pieces
        othelloBoard [4][4] = position.WHITE;
        othelloBoard [4][5] = position.WHITE;
        othelloBoard [5][4] = position.WHITE;
        othelloBoard [5][5] = position.WHITE;


        //up black pieces
        othelloBoard [2][4] = position.BLACK;
        othelloBoard [2][5] = position.BLACK;
        othelloBoard [3][4] = position.BLACK;
        othelloBoard [3][5] = position.BLACK;

        //down balck pieces
        othelloBoard[4][2] = position.BLACK;
        othelloBoard[4][3] = position.BLACK;
        othelloBoard[5][2] = position.BLACK;
        othelloBoard[5][3] = position.BLACK;

    }

    // new method
    void printBoard(){

        //drawing the board
        cout <<"    1   2   3   4   5   6   7   8"<< endl;
        cout <<"  +---+---+---+---+---+---+---+---+"<<endl;

        for (int i = 0; i < 8; ++i) {
            cout <<i+1 << " |";
            for (int j = 0; j < 8; ++j) {
                cout <<" " << othelloBoard[i][j]<<" |";
            }
            cout <<" "<< endl;
            cout <<"  +---+---+---+---+---+---+---+---+"<<endl;
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

   void takeTurn(Player* currentPlayer){
        cout << "It's " << currentPlayer->getNamePlayer() <<"'s turn."<<endl;
    }

    //this method verifies if the player input is playable or not
  bool verificationBoardPositionPlayer(int column, int row){

        bool good = true;

        if (othelloBoard[column][row] == unPlayablePosition.WHITE || othelloBoard [column][row] == unPlayablePosition.BLACK || othelloBoard[column][row] == unPlayablePosition.UNPLAYABLE){
            good = unPlayablePosition.canPlay();
        } else {
            good = position.canPlay();

        }

        return good;
    }


   void newPiecePositionBoard(int col, int row, char colourPlayer){

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                othelloBoard[col][row] = colourPlayer;
            }
        }
    }

    char countingPiece(){

        int countingWhitePieces = 0;
        int countingBlackPieces = 0;
        char winningPiece;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {

                if (othelloBoard[i][j] == position.BLACK){
                    countingBlackPieces++;
                }
                if (othelloBoard[i][j] == position.WHITE){
                    countingWhitePieces++;
                }

            }
        }
        cout <<"There are " << countingBlackPieces << " black pieces" << endl;
        cout <<"There are " << countingWhitePieces << " white pieces" << endl;

        if (countingBlackPieces > countingWhitePieces){
            winningPiece = position.BLACK;
        }
        if (countingWhitePieces > countingBlackPieces){
            winningPiece = position.WHITE;
        }
        if (countingWhitePieces == countingBlackPieces){
            winningPiece = 'T';
        }

        return winningPiece;
    }


  bool  verifyAvailableMoves (bool availableMoves){

         //verifies if the board has available empty spaces
         for (int i = 0; i < 8; i++)
         {
            for (int j = 0; j < 8; j++)
            {
                if (othelloBoard[i][j] == position.EMPTY){
                       availableMoves = true;
                }
            }
         }

return availableMoves;
    
}


    void flipPieces(int column, int row, char colourPlayer) {

        if (colourPlayer == 'B') {

            //checking the row to the right
            if (row < 6 && othelloBoard[column][row + 1] != colourPlayer && othelloBoard[column][row + 1] != position.EMPTY) {
                for (int i = row + 2; i < 8; ++i) {
                    if (othelloBoard[column][i] == colourPlayer) {
                        for (int j = row + 1; j < i; ++j) {
                            othelloBoard[column][j] = colourPlayer;
                        }
                        break;
                    }
                }
            }

            //checking the row to the left
            if (row > 1 && othelloBoard[column][row - 1] != colourPlayer && othelloBoard [column][row - 1] != position.EMPTY){
                for (int i = row - 2; i < 8 ; --i) {
                    if (othelloBoard[column][i] == colourPlayer){
                        for (int j = row - 1 ; j > i ; --j) {
                            othelloBoard [column][j] = colourPlayer;
                        }
                        break;
                    }
                }

            }

            //checking the column downwards
            if (column < 6 && othelloBoard[column + 1][row] != colourPlayer && othelloBoard[column+1][row] != position.EMPTY){
                for (int i = column + 2; i < 8; ++i) {
                    if (othelloBoard[i][row] == colourPlayer){
                        for (int j = column + 1; j < i; ++j) {
                            othelloBoard[j][row] = colourPlayer;
                        }
                        break;
                    }

                }
            }

            //checking the column upwards
            if (column > 1 && othelloBoard[column - 1] [row] != colourPlayer && othelloBoard[column-1][row] != position.EMPTY){

                for (int i = column - 2; i < 8; --i) {
                    if (othelloBoard[i][row] == colourPlayer){
                        for (int j = column - 1; j > i ; --j) {
                           othelloBoard[j][row] = colourPlayer;
                        }
                        break;
                    }

                }
            }

            /*
            //checking up to the left
            if (column > 1 && row > 1 && othelloBoard[column -1] [row - 1] != colourPlayer && othelloBoard [column-1][row-1] != position.EMPTY){
                for (int i = column -2 ; i < 8 ; --i) {
                    if (othelloBoard[i][row-1] == colourPlayer){
                        for (int j = column - 1; j > i ; --j) {
                            othelloBoard[j][row-1] = colourPlayer;
                        }
                        break;
                    }

                }
            }



            /*
            //checking up to the right
            if(column > 1 && row < 8 && othelloBoard [column - 1][row+1] != colourPlayer && othelloBoard [column-1][row +1] != position.EMPTY){
                for(int i = column - 1 ; i < 8; i--){
                    if (othelloBoard[i][row+1] == colourPlayer){
                        for (int j = column - 1; j > i ; --j) {
                            othelloBoard[j][row+1] = colourPlayer;
                        }
                        break;
                    }

                }
            }

            //checking down to the left
            if()
            */

        } else if (colourPlayer == 'W') {

            //checking the row to the right
            if (row < 6 && othelloBoard[column][row + 1] != colourPlayer && othelloBoard[column][row + 1] != position.EMPTY) {
                for (int i = row + 2; i < 8; ++i) {
                    if (othelloBoard[column][i] == colourPlayer) {
                        for (int j = row + 1; j < i; ++j) {
                            othelloBoard[column][j] = colourPlayer;
                        }
                        break;
                    }
                }
            }

            //checking the row to the left
            if (row > 1 && othelloBoard[column][row - 1] != colourPlayer && othelloBoard [column][row - 1] != position.EMPTY){
                for (int i = row - 2; i < 8 ; --i) {
                    if (othelloBoard[column][i] == colourPlayer){
                        for (int j = row - 1 ; j > i ; --j) {
                            othelloBoard [column][j] = colourPlayer;
                        }
                        break;
                    }
                }

            }

            //checking the column downwards
            if (column < 6 && othelloBoard[column + 1][row] != colourPlayer && othelloBoard[column+1][row] != position.EMPTY){
                for (int i = column + 2; i < 8; ++i) {
                    if (othelloBoard[i][row] == colourPlayer){
                        for (int j = column + 1; j < i; ++j) {
                            othelloBoard[j][row] = colourPlayer;
                        }
                        break;
                    }

                }
            }

            //checking the column upwards
            if (column > 1 && othelloBoard[column - 1] [row] != colourPlayer && othelloBoard[column-1][row] != position.EMPTY){

                for (int i = column - 2; i < 8; --i) {
                    if (othelloBoard[i][row] == colourPlayer){
                        for (int j = column - 1; j > i ; --j) {
                            othelloBoard[j][row] = colourPlayer;
                        }
                        break;
                    }

                }
            }


            }
    }
    
};


#endif //ASSIGNMENT2COEN244_BOARD_H
