#include <iostream>
#include <string>
#include "block.h"
#include "board.h"
using namespace std;

Block::Block(char type, int x, int y, int level): type{type}, orientation{0}, level{level} {
    BLcoords = new Coordinate(x,y);
}
Block::~Block() {};

vector<Coordinate*> Block::getcList () {
    return cList;
}

Coordinate* Block::getBL() {
    return BLcoords;
}


void Block::rotate(int n) {
    DOrotate(n);
}

void Block::removeCoordinate(int x, int y) {
    for (int i = 0; i < cList.size(); i++) {
        if (cList[i]->x == x && cList[i]->y == y) {
            delete cList[i];
            cList.erase(cList.begin()+i);
        }
    }

    if (BLcoords->x == x && BLcoords->y == y) {
        delete BLcoords;
        if (howManyCoords() > 0) {
            BLcoords = findNewBL();
        } else {
            BLcoords = new Coordinate(-1, -1);
        }
    }
}

void Block::decrementCoordinate(int x, int y) {
    for (int i = 0; i < cList.size(); i++) {
        if (cList[i]->x == x && cList[i]->y == y) {
            cList[i]->y -= 1;
        }
    }
}

int Block::howManyCoords() {
    int counter = 0;
    for (int i = 0; i < cList.size(); i++) {
        counter++;
    }
    return counter;
}

int Block::getLevel() {
    return level;
}

Coordinate* Block::findNewBL() {
    int minimumX = cList[0]->x;
    int minimumY = cList[0]->y;
    for (int i = 1; i < cList.size(); i++) {
        if (cList[i]->x < minimumX) {
            minimumX = cList[i]->x;
        }
        if (cList[i]->y < minimumY) {
            minimumY = cList[i]->y;
        }
    }
    return new Coordinate(minimumX, minimumY);
}

void Block::updateCoordinates(int x, int y) {
    int xdiff = BLcoords->x - x;
    int ydiff = BLcoords->y - y;

    BLcoords->x = BLcoords->x - xdiff;
    BLcoords->y = BLcoords->y - ydiff;
    for (int i = 0; i < cList.size(); i++) {
        cList[i]->x = cList[i]->x - xdiff;
        cList[i]->y = cList[i]->y - ydiff;
    }
}

char Block::getType() {
    return type;
}