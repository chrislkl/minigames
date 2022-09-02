#include <iostream>
#include <string>
#include "oblock.h"
#include "board.h"
using namespace std;

OBlock::OBlock(char type, int x, int y, int level): Block(type, x, y, level) {
    cList.emplace_back(new Coordinate(x,y));
    cList.emplace_back(new Coordinate(x,y+1));
    cList.emplace_back(new Coordinate(x+1,y));
    cList.emplace_back(new Coordinate(x+1,y+1));
}

OBlock::~OBlock() { 
    for (int i = 0; i < cList.size(); i++) {
        delete cList[i];
    }
    delete BLcoords;
};

void OBlock::DOrotate(int n) {
    orientation = orientation + n;
    if (orientation == -1) {
        orientation = 3;
    } else if (orientation == 4) {
        orientation = 0;
    }
    
}