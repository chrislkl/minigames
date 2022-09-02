#include <iostream>
#include <string>
#include "sblock.h"
#include "board.h"
using namespace std;

SBlock::SBlock(char type, int x, int y, int level): Block(type, x, y, level) {
    cList.emplace_back(new Coordinate(x,y));
    cList.emplace_back(new Coordinate(x+1,y));
    cList.emplace_back(new Coordinate(x+1,y+1));
    cList.emplace_back(new Coordinate(x+2,y+1));
}

SBlock::~SBlock() { 
    for (int i = 0; i < cList.size(); i++) {
        delete cList[i];
    }
    delete BLcoords;
};

void SBlock::DOrotate(int n) {
    int x = BLcoords->x;
    int y = BLcoords->y;
    orientation = orientation + n;
    if (orientation == -1) {
        orientation = 3;
    } else if (orientation == 4) {
        orientation = 0;
    }
    if (orientation == 1 || orientation == 3) {
        for (int i = 0; i < cList.size(); i++) {
            delete cList[i];
        }
        cList.clear();
        
        cList.emplace_back(new Coordinate(x+1,y));
        cList.emplace_back(new Coordinate(x,y+1));
        cList.emplace_back(new Coordinate(x,y+2));
        cList.emplace_back(new Coordinate(x+1,y+1));

        
    } else if (orientation == 0 || orientation == 2) {
        for (int i = 0; i < cList.size(); i++) {
            delete cList[i];
        }
        cList.clear();

        cList.emplace_back(new Coordinate(x,y));
        cList.emplace_back(new Coordinate(x+1,y));
        cList.emplace_back(new Coordinate(x+1,y+1));
        cList.emplace_back(new Coordinate(x+2,y+1));
    }
}