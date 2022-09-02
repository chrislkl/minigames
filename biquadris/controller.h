#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include <iostream>
#include <string>
#include <vector>
#include "interface.h"

class Controller {
    Interface *iface1;
    Interface *iface2;
    Interface *turn;
    int highScore1;
    int highScore2;
    std::string file1;
    std::string file2;
    int startLevel;
    int row;
    int col;

    public:
    Controller(int, int, std::string, std::string, int);
    ~Controller();

    void printController();
    void action(std::string, int);
    void switchTurn();
    bool getSpecialAction();
    void updateSpecialAction(bool);
    void applyBlind();
    void applyHeavy();
    bool getHeavySwitch();
    void falseHeavySwitch();
    void applyForce();
    void doForce(std::string);
    bool getEndGame();
    void doEndGame();
};

#endif