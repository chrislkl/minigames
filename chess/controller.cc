#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "controller.h"
using namespace std;

Controller::Controller(std::string black, std::string white, bool setup): black{black}, white{white} {
    b = new Board(setup);
    turn = "white";
    blackScore = 0;
    whiteScore = 0;
}

void Controller::updateBlack(string name) {
    black = name;
}

void Controller::updateWhite(string name) {
    white = name;
}

void Controller::updateTurn(string name) {
    turn = name;
}

void Controller::addOneScore(string name) { //name is loser
    if (name == "white") {
        blackScore = blackScore + 1;
    } else {
        whiteScore = whiteScore + 1;
    }
}

void Controller::addHalfScore() {
    blackScore = blackScore + 0.5;
    whiteScore = whiteScore + 0.5;
}

void Controller::replaceBoard(bool setup) {
    delete b;
    b = new Board(setup);
}

string Controller::checkCheckmate(string player) {
    return b->checkCheckmate(player);
}

double Controller::getBlackScore() {
    return blackScore;
}

double Controller::getWhiteScore() {
    return whiteScore;
}

void Controller::action(string s) {
    if (s == "move") {
        string first;
        string second;
        cin >> first;
        cin >> second;
        int fromX = coordsToXInt(first);
        int fromY = coordsToYInt(first);
        int toX = coordsToXInt(second);
        int toY = coordsToYInt(second);
        if (b->getPlayerAt(fromX, fromY) != turn) {
            throw std::logic_error {b->getPlayerAt(fromX, fromY)};
        }
        b->move(fromX, fromY, toX, toY);
        b->checkPawnPromotion(toX, toY);
        b->printBoard();

        if (turn == "white") {
            turn = "black";
        } else {
            turn = "white";
        }
    } else {
        throw std::logic_error {"a"};
    }
}

void Controller::compAction(string level) {
    if (level == "computer1") {
        int placeX;
        int placeY;
        srand((unsigned int)time(NULL));
        int x = rand() % 8;
        int y = rand() % 8;
        do {
            x = rand() % 8;
            y = rand() % 8;
            while (b->getPlayerAt(x,y) != turn) {
                x = rand() % 8;
                y = rand() % 8;
            }
            vector<int> place;
            place = b->getRandomLegalMove(x,y);
            placeX = place[0];
            placeY = place[1];
        }
        while (placeX == -1);

        b->move(x,y,placeX,placeY);
        b->promotePawnComp(placeX, placeY);
        b->printBoard();
    }  else if (level == "computer2") {
        vector<int> place;
        place = b->getRandomCaptureMove(turn);
        int placeX = place[0];
        int placeY = place[1];
        if (placeX != -1) {
            int x = place[2];
            int y = place[3];
            b->move(x,y,placeX,placeY);
            b->promotePawnComp(placeX, placeY);
            b->printBoard();
        } else {
            place = b->getRandomCheckMove(turn);
            int placeX = place[0];
            int placeY = place[1];
            if (placeX != -1) {
                int x = place[2];
                int y = place[3];
                b->move(x,y,placeX,placeY);
                b->promotePawnComp(placeX, placeY);
                b->printBoard();
            } else {
                //random
                srand((unsigned int)time(NULL));
                int x = rand() % 8;
                int y = rand() % 8;
                do {
                    x = rand() % 8;
                    y = rand() % 8;
                    while (b->getPlayerAt(x,y) != turn) {
                        x = rand() % 8;
                        y = rand() % 8;
                    }
                    vector<int> place;
                    place = b->getRandomLegalMove(x,y);
                    placeX = place[0];
                    placeY = place[1];
                }
                while (placeX == -1);
                b->move(x,y,placeX,placeY);
                b->promotePawnComp(placeX, placeY);
                b->printBoard();
            }
        }
    }  else if (level == "computer3") {
        vector<int> place;
        place = b->getRandomThreatenedPiece(turn);
        int placeX = place[0];
        int placeY = place[1];
        if (placeX != -1) {
            place = b->getRandomAvoidCaptureMove(placeX, placeY);
            int toX = place[0];
            int toY = place[1];
            if (toX != -1) {
                b->move(placeX, placeY, toX, toY);
                b->promotePawnComp(toX, toY);
                b->printBoard();
            } else {
                goto cantAvoidCapture;
            }
        } else {
            cantAvoidCapture:
            place = b->getRandomCaptureMove(turn);
            int placeX = place[0];
            int placeY = place[1];
            if (placeX != -1) {
                int x = place[2];
                int y = place[3];
                b->move(x,y,placeX,placeY);
                b->promotePawnComp(placeX, placeY);
                b->printBoard();
            } else {
                place = b->getRandomCheckMove(turn);
                int placeX = place[0];
                int placeY = place[1];
                if (placeX != -1) {
                    int x = place[2];
                    int y = place[3];
                    b->move(x,y,placeX,placeY);
                    b->promotePawnComp(placeX, placeY);
                    b->printBoard();
                } else {
                    //random
                    srand((unsigned int)time(NULL));
                    int x = rand() % 8;
                    int y = rand() % 8;
                    do {
                        x = rand() % 8;
                        y = rand() % 8;
                        while (b->getPlayerAt(x,y) != turn) {
                            x = rand() % 8;
                            y = rand() % 8;
                        }
                        vector<int> place;
                        place = b->getRandomLegalMove(x,y);
                        placeX = place[0];
                        placeY = place[1];
                    }
                    while (placeX == -1);
                    b->move(x,y,placeX,placeY);
                    b->promotePawnComp(placeX, placeY);
                    b->printBoard();
                }
            }
        }
    }
    if (turn == "white") {
        turn = "black";
    } else {
        turn = "white";
    }
}

void Controller::setup(string s) {
    if (s == "+") {
        string name;
        string place;
        cin >> name;
        cin >> place;
        int x = coordsToXInt(place);
        int y = coordsToYInt(place);
        char charname = name[0];
        if (validPieceName(charname)) {
            if (charname < 'Z') {
                b->place(charname, x, y, "white");
            } else {
                b->place(charname, x, y, "black");
            }
            printBoard();
        }
    } else if (s == "-") {
        string place;
        cin >> place;
        int x = coordsToXInt(place);
        int y = coordsToYInt(place);
        b->remove(x,y);
        printBoard();
    } else if (s == "=") {
        string color;
        cin >> color;
        if (color == "white" || color == "black") {
            updateTurn(color);
        }
    }
}

string Controller::getBlack() {
    return black;
}

string Controller::getWhite() {
    return white;
}

bool Controller::checkCheck(string player) {
    return (b->isThreatened(b->locateKingX(player),b->locateKingY(player)));
}

bool Controller::isValidSetup() {
    if (b->twoKingsExist() && b->noPawnsFirstandLastRow()) {
        if (!(b->isThreatened(b->locateKingX("white"), b->locateKingY("white"))) && !(b->isThreatened(b->locateKingX("black"), b->locateKingY("black")))) {
            return true;
        }
    }
    return false;
}

bool Controller::checkStalemate(string player) {
    return b->checkStalemate(player);
}

void Controller::printBoard() {
    b->printBoard();
}

Controller::~Controller() {
    delete b;
}

bool validPieceName(char c) {
    if (c == 'p' || c == 'P' || c == 'k' || c == 'K' || c == 'n' || c == 'N' || c == 'b' || c == 'B' || c == 'q' || c == 'Q' || c == 'r' || c == 'R') {
        return true;
    } else {
         throw logic_error {"a"};
    }
}

string Controller::getTurn() {
    return turn;
}

int coordsToXInt(string s) { 
    char x = s[0];
    if (x < 'a' || x > 'h') {
        throw std::logic_error {"a"};
    }
    const int convert = 'a';
    int finalx = x - convert;
    return finalx;
}

int coordsToYInt(string s) { 
    char y = s[1];
    if (y < '1' || y > '8') {
        throw std::logic_error {"a"};
    }
    const int convert = '0'+1;
    int finaly = y - convert;
    return finaly;
}