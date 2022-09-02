#include <iostream>
#include <string>
#include <vector>
#include "controller.h"
using namespace std;


Controller::Controller(int row, int col, string file1, string file2, int level): row{row}, col{col}, highScore1{0}, highScore2{0}, startLevel{level}, file1{file1}, file2{file2}  {
    iface1 = new Interface(row, col, file1, level, highScore1);
    iface2 = new Interface(row, col, file2, level, highScore2);
    turn = iface1;
}

Controller::~Controller() {
    delete iface1;
    delete iface2;
}

void Controller::switchTurn() {
    if (turn == iface1) {
        turn = iface2;
    } else if (turn == iface2) {
        turn = iface1;
    }
}

void Controller::doForce(string blockName) {
    turn->activateForce(blockName);
}

bool Controller::getEndGame() {
    return turn->getEndGame();
}

void Controller::printController() {
    for (int y = turn->getRowTotal()+3; y >= -4; y--) {
        iface1->printBoardInterfaceLine(y, false);
        iface2->printBoardInterfaceLine(y, true);
    }
    cout << endl;
}

void Controller::doEndGame() {
    if (iface1->gethighScore() > highScore1) {
        highScore1 = iface1->gethighScore();
    }
    if (iface2->gethighScore() > highScore2) {
        highScore2 = iface2->gethighScore();
    }
    delete iface1;
    delete iface2;
    iface1 = new Interface(row, col, file1, startLevel, highScore1);
    iface2 = new Interface(row, col, file2, startLevel, highScore2);
    turn = iface2;
}

void Controller::action(string act, int num) {
    turn->action(act, num);
}

bool Controller::getSpecialAction() {
    return turn->specialAction;
}

void Controller::applyBlind() {
    turn->blind = true;
}

void Controller::applyHeavy() {
    turn->heavy = true;
}

bool Controller::getHeavySwitch() {
    return turn->heavySwitch;
}

void Controller::falseHeavySwitch() {
    turn->heavySwitch = false;
}

void Controller::applyForce() {
    turn->force = true;
}

void Controller::updateSpecialAction(bool special) {
    turn->specialAction = special;
}