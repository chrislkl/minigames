#include <iostream>
#include <string>
#include "tblock.h"
#include "board.h"
using namespace std;

TBlock::TBlock(char type, int x, int y, int level): Block(type, x, y, level) {
    cList.emplace_back(new Coordinate(x,y+1));
    cList.emplace_back(new Coordinate(x+1,y+1));
    cList.emplace_back(new Coordinate(x+1,y));
    cList.emplace_back(new Coordinate(x+2,y+1));
}

TBlock::~TBlock() { 
    for (int i = 0; i < cList.size(); i++) {
        delete cList[i];
    }
    delete BLcoords;
};

void TBlock::DOrotate(int n) {
    int x = BLcoords->x;
    int y = BLcoords->y;
    orientation = orientation + n;
    if (orientation == -1) {
        orientation = 3;
    } else if (orientation == 4) {
        orientation = 0;
    }
    if (orientation == 1) {
        for (int i = 0; i < cList.size(); i++) {
            delete cList[i];
        }
        cList.clear();
        
        cList.emplace_back(new Coordinate(x+1,y));
        cList.emplace_back(new Coordinate(x,y+1));
        cList.emplace_back(new Coordinate(x+1,y+1));
        cList.emplace_back(new Coordinate(x+1,y+2));

        
    } else if (orientation == 2) {
        for (int i = 0; i < cList.size(); i++) {
            delete cList[i];
        }
        cList.clear();

        cList.emplace_back(new Coordinate(x,y));
        cList.emplace_back(new Coordinate(x+1,y+1));
        cList.emplace_back(new Coordinate(x+2,y));
        cList.emplace_back(new Coordinate(x+1,y));
    } else if (orientation == 3) {
        for (int i = 0; i < cList.size(); i++) {
            delete cList[i];
        }
        cList.clear();

        cList.emplace_back(new Coordinate(x,y));
        cList.emplace_back(new Coordinate(x,y+1));
        cList.emplace_back(new Coordinate(x+1,y+1));
        cList.emplace_back(new Coordinate(x,y+2));
    } else if (orientation == 0) {
        for (int i = 0; i < cList.size(); i++) {
            delete cList[i];
        }
        cList.clear();

        cList.emplace_back(new Coordinate(x,y+1));
        cList.emplace_back(new Coordinate(x+1,y+1));
        cList.emplace_back(new Coordinate(x+1,y));
        cList.emplace_back(new Coordinate(x+2,y+1));
    }
}