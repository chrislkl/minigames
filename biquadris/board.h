#ifndef _BOARD_H_
#define _BOARD_H_
#include <iostream>a
#include <string>
#include <vector>
#include "block.h"
#include "jblock.h"
#include "noblock.h"
#include "iblock.h"
#include "lblock.h"
#include "zblock.h"
#include "sblock.h"
#include "tblock.h"
#include "oblock.h"
#include "tile.h"
#include "onebyone.h"

class Board {
    int row;
    int rowTotal;
    int col;
    std::vector<std::vector<Tile*>> grid;
    std::vector<Block*> hasBlocks;
    public:
    int turnsWithoutClear;
    Board(int, int);
    ~Board();

    int getRowTotal();
    int getRow();
    int getCol();

    void printBoard();
    void printBoardLine(int, bool, bool);
    void placeBlock(int, int, Block *); // assumes valid placement (ie: all tiles it gets placed on contain NoBlock blocks)
    bool canPlace(int, int, Block *); //
    bool checkBounds(int, int, Block *);
    bool canRemoveBlock(int, int);
    void removeBlock(Block *);
    bool canDown(Block *); 
    void moveDown(Block *);
    bool canLeft(Block *); 
    void moveLeft(Block *);
    bool canRight(Block *); 
    void drop(Block *);
    void moveRight(Block *);
    bool containBlock(Block *);

    int howManyFullLines();
    int detectFullLines(); // returns y coordinates of most bottom full line in board 
    void removeLine(int); // removes lines at y coordinates store in vector (and replaces them with empty lines at the top)
    void decrementCoords(int);
    std::vector<int> removeEmptyBlocks(); // removes blocks in HasBlocks that are no longer on the board + returns a vector of the levels of each block

    void rotate(Block *, int);
};


#endif
