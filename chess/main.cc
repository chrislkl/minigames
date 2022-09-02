#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "controller.h"
#include "board.h"
#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "knight.h"
#include "nopiece.h"

int main () {

    int counter = 0;

    string s;
    string act;
    bool hasSetup = false; 
    Controller* c = new Controller("human", "human", true);
    while (cin >> s) {
        if (!hasSetup) {
            c->replaceBoard(true);
        }

        if (s == "game") {
            string white_player;
            string black_player;
            cin >> white_player;
            cin >> black_player;
            if (white_player != "human" && white_player != "computer1" && white_player != "computer2" && white_player != "computer3" && white_player != "computer4") {
                break; //throw
            }

            if (!hasSetup) {
                c->replaceBoard(false);
            }
            c->updateBlack(black_player);
            c->updateWhite(white_player);
            c->printBoard();
            while (true) {
                if (c->checkStalemate(c->getTurn())) {
                    c->addHalfScore();
                    cout << "Stalemate!" << endl;
                    c->updateTurn("white"); 
                    break;
                }
                string loser = c->checkCheckmate(c->getTurn());
                if (loser != "none") {
                    c->addOneScore(loser);
                    if (loser == "white") {
                        cout << "Black wins!" << endl;
                    } else {
                        cout << "White wins!" << endl;
                    }
                    c->updateTurn("white");
                    break;
                }

                if (c->checkCheck("white")) {
                    cout << "White is in check." << endl;
                } else if (c->checkCheck("black")) {
                    cout << "Black is in check." << endl;
                }

                cout << c->getTurn() << "'s turn:" << endl;

                if ((c->getTurn() == "white" && c->getWhite() == "human") || (c->getTurn() == "black" && c->getBlack() == "human")) {
                    string act;
                    if (!(cin >> act)) {
                        break;
                    }
                    if (act == "resign") {
                        c->addOneScore(c->getTurn());
                        if (c->getTurn() == "white") {
                            cout << "Black wins!" << endl;
                        } else {
                            cout << "White wins!" << endl;
                        }
                        c->updateTurn("white");
                        break;
                    }
                    try {
                        c->action(act);
                    }
                    catch (logic_error var) {
                        cerr << "That is not a valid command. Please enter your command again:" << endl;
                    }
                } else { // computers turn
                    if (c->getTurn() == "white") {
                        c->compAction(c->getWhite());
                    } else {
                        c->compAction(c->getBlack());
                    }
                }
            }
            hasSetup = false;
        } else if (s == "setup") {
            hasSetup = true;
            c->printBoard();
            while (cin >> s) {
                if (s == "done") {
                    if (c->isValidSetup()) {
                        break;
                    } else {
                        cerr << "Not a valid setup." << endl;
                    }
                }
                try {
                    c->setup(s);
                }
                catch (logic_error var) {
                    cerr << "That is not a valid command. Please enter you command again:" << endl;
                }
            }
        } else {
            cerr << "That is not a valid command. Please enter your command again:" << endl;
        }
    }

    cout << "Final Score:" << endl;
    cout << "White: " << c->getWhiteScore() << endl;
    cout << "Black: " << c->getBlackScore() << endl;
    delete c;
}
