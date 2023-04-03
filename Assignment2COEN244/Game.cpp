//
// Created by Thomas Mejia on 2023-03-15.
//

#include "Game.h"
void Game :: save(){

    string filename;

    int choicePlayer = 0;
    int resumePlayer = 0;
    bool correctNumber = true;

    while (correctNumber == true) {

        try {
            cout << "*****************************************" << endl;
            cout << "* Would you like to save your progress? *" << endl;
            cout << "* 1. Yes                                *" << endl;
            cout << "* 2. No                                 *" << endl;
            cout << "*****************************************" << endl;

            cin >> choicePlayer;

            if ((choicePlayer != 1) && (choicePlayer != 2)) {
                correctNumber = true;
                throw 1;
            } else{
                correctNumber = false;
            }

            if (choicePlayer == 1) {

                cout << "Please write a name of your game and must end with a .txt" << endl;
                cin >> filename;

                fstream saveGame(filename, ios :: out);
                if (saveGame.is_open()) {

                    saveGame << player1.getNamePlayer() << endl;
                    saveGame << player2.getNamePlayer() << endl;
                    saveGame << currentPlayer->getNamePlayer()<<endl;

                    for (int i = 0; i < 8; ++i) {
                        for (int j = 0; j < 8; ++j) {
                            saveGame << board.othelloBoard[i][j];
                        }
                        saveGame << endl;
                    }

                    saveGame.close();
                    cout << "The game has been saved as " << filename << endl;
                }


                cout <<"***********************************************"<<endl;
                cout <<"* Would you like to continue the game?        *" <<endl;
                cout <<"* 1. Yes                                      *" <<endl;
                cout <<"* 2. No                                       *" << endl;
                cout <<"***********************************************" <<endl;

                cin >> resumePlayer;

                if ((resumePlayer != 1 ) && (resumePlayer != 2)){
                    correctNumber = true;
                    throw 1;
                } else {
                    correctNumber = false;
                }

                if (resumePlayer == 1){
                    cout << "The game may resume." << endl;
                    play();
                }
                if (resumePlayer == 2){
                    cout << "Thanks for playing!" << endl;
                    exit(0);
                }

            }

            if (choicePlayer == 2) {

                cout << "The game may resume " << endl;
                play();
            }




            /*
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    cout << board.othelloBoard[i][j];
                }
                cout << " " << endl;
            }
        */




        } catch(int notGoodNumber) {
            cout << "Please try again. Type between 1 and 2." << endl;
            cout << "***********************" << endl;

        }
    }




}

void Game ::load() {


  string filename;
  cout << "Please write the name of the game which ends with a .txt" << endl;
  cin >> filename;

  ifstream gameFile(filename);

  if (gameFile){
      cout << "This game file exits" << endl;

     // getline(filename,namePlayer1); checks the first line
     // getline(filename,namePlayer2); checks the second line
     // getline(filename,currentPlayer); checks the third line

     /*
      for (int i = 0; i < 8; ++i) {
          for (int j = 0; j < 8; ++j) {

              gameFile >> board.othelloBoard[i][j];
          }
      }

  for (int i = 0; i < 8; ++i) {
          for (int j = 0; j < 8; ++j) {
              cout << board.othelloBoard[i][j];
          }
          cout <<endl;
      }
      */



  } else{
      cout <<"This game file does not exist. The game may close." << endl;
      exit (0);
  }








}


