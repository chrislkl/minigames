#ifndef _TILE_H_
#define _TILE_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class Tile {
    Block *block;
    char type;
    public:
    void changeNoBlock(Block *); // only for noblocks
    void changeBlock(Block *); // for a block to no block
    void updateType(char);
    Block* getBlock();

    Tile(Block*, char);
    char getType();
    ~Tile();
};

#endif
