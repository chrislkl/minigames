#include <iostream>
#include <string>
#include "onebyone.h"
#include "board.h"
using namespace std;

Onebyone::Onebyone(char type, int x, int y, int level): Block(type, x, y, level) {
    cList.emplace_back(new Coordinate(x,y));
}

Onebyone::~Onebyone() { 
    for (int i = 0; i < cList.size(); i++) {
        delete cList[i];
    }
    delete BLcoords;
};

void Onebyone::DOrotate(int n) {
    //does not rotate
}