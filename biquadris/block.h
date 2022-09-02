#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <string>
#include <vector>
#include "coordinate.h"

class Block {
    protected:
    char type;
    Coordinate *BLcoords; 
    std::vector<Coordinate*> cList;
    int orientation;
    int level;

    virtual void DOrotate(int) = 0; //assumes block is full (no parts removed)

    public:
    std::vector<Coordinate*> getcList ();
    char getType();
    Coordinate* getBL();
    int getLevel();

    void updateCoordinates(int x, int y); // if block were to be move to (x,y), update all coordinates to match that
    void removeCoordinate(int x, int y); //assumes x, y is a coordinate in the block
    Coordinate* findNewBL(); //assumes at least 1 coordinate stored
    int howManyCoords(); 
    void decrementCoordinate(int x, int y); // decrease y by 1 IFF x,y is a coord in cList

    Block(char, int, int, int);

    void rotate(int);

    virtual ~Block() = 0;
};

#endif
