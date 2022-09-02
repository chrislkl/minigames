#include <iostream>
#include <string>
#include "board.h"
using namespace std;

Board::Board(int row, int col): row{row}, col{col}, rowTotal{row+3}, turnsWithoutClear{0} {
    for (int j = 0; j < col; j++) {
        vector<Tile*> v1;
        for (int i = 0; i < rowTotal; i++) {
            v1.emplace_back(new Tile(new NoBlock(' ', j, i, 0), ' '));
        }
        grid.emplace_back(v1);
    }
}

Board::~Board() {
    for (int j = rowTotal-1; j >= 0; j--) {
        for (int i = 0; i < col; i++) {
            delete grid[i][j];
        }
    }
    for (int i = 0; i < hasBlocks.size(); i++) {
        delete hasBlocks[i];
    }
}

void Board::printBoard() {
    for (int j = rowTotal-1; j >= 0; j--) {
        for (int i = 0; i < col; i++) {
            cout << grid[i][j]->getType();
        }
        cout << endl;
    }
}

void Board::printBoardLine(int y, bool newLine, bool blind) {
    for (int i = 0; i < col; i++) {
        if (blind) {
            if (y >= 2 && y <= 11 && i >= 2 && i <= 8) {
                cout << "?";
            } else {
                cout << grid[i][y]->getType();
            }
        } else {
            cout << grid[i][y]->getType();
        }
    }
    if (newLine) {
        cout << endl;
    } else {
        cout << "     ";
    }
}

int Board::getRow() {
    return row;
}

int Board::getRowTotal() {
    return rowTotal;
}

int Board::getCol() {
    return col;
}

bool Board::checkBounds(int x, int y, Block *block) {
    if ((x < 0) || (y < 0) || (x > col-1) || (y > row)) {
        return false;
    }
    Coordinate *bl = block->getBL();
    int tmpx = bl->x;
    int tmpy = bl->y;
    block->updateCoordinates(x,y);
    vector<Coordinate*> coords = block->getcList(); 
    for (int i = 0; i < coords.size(); i++) {
        if (coords[i]->x > (col-1) || coords[i]->x > (rowTotal-1)) {
            block->updateCoordinates(tmpx,tmpy);
            return false;
        }
    }
    block->updateCoordinates(tmpx,tmpy);
    return true;
}

bool Board::canPlace(int x, int y, Block *block) {
    if(!checkBounds(x,y,block)) {
        return false;
    }
    Coordinate *bl = block->getBL();
    int tmpx = bl->x;
    int tmpy = bl->y;
    block->updateCoordinates(x,y);
    vector<Coordinate*> coords = block->getcList(); 
    for (int i = 0; i < coords.size(); i++) {
        if (grid[coords[i]->x][coords[i]->y]->getType() != ' ') {
            block->updateCoordinates(tmpx,tmpy);
            return false;
        }
    }
    block->updateCoordinates(tmpx,tmpy);
    return true;
}

bool Board::canRemoveBlock(int x, int y) {
    if (grid[x][y]->getType() == ' ') {
        return false;
    } else {
        return true;
    }
}

void Board::rotate(Block *block, int n){
    removeBlock(block);
    block->rotate(n);

    if (canPlace(block->getBL()->x,block->getBL()->y,block)) {
        placeBlock(block->getBL()->x,block->getBL()->y,block);
    } else {
        block->rotate(-n);
        placeBlock(block->getBL()->x,block->getBL()->y,block);
    }
}

void Board::removeBlock(Block *block) { 
    vector<Coordinate*> coords = block->getcList();
    for (int i = 0; i < coords.size(); i++) {
       grid[coords[i]->x][coords[i]->y]->changeBlock(new NoBlock(' ', coords[i]->x, coords[i]->y, 0));
       grid[coords[i]->x][coords[i]->y]->updateType(' ');
    }
    for (int i = 0; i < hasBlocks.size(); i++) {
        if (hasBlocks[i] == block) {
            hasBlocks.erase(hasBlocks.begin() + i);
        }
    }
}

int Board::howManyFullLines() {
    int counter = 0;
    for (int j = 0; j < rowTotal; j++) {
        for (int i = 0; i < col; i++) {
            if (grid[i][j]->getType() == ' ') {
                break;
            }
            if (i == col-1) {
                counter++;
            }
        }
    }
    return counter;
}

int Board::detectFullLines() {
    for (int j = 0; j < rowTotal; j++) {
        for (int i = 0; i < col; i++) {
            if (grid[i][j]->getType() == ' ') {
                break;
            }
            if (i == col-1) {
                return j;
            }
        }
    }
    return -1;
}

void Board::decrementCoords(int y) { //decrement at y or above
    for (int j = y; j < rowTotal; j++) {
        for (int i = 0; i < col; i++) {
            if (grid[i][j]->getType() != ' ') {
                grid[i][j]->getBlock()->decrementCoordinate(i,j+1);
            }
        }
    }
}

void Board::removeLine(int y) {
    for (int j = 0; j < col; j++) {
        // first, tell the block stored in grid[j][y] to remove (j,y) as a coordinate
        grid[j][y]->getBlock()->removeCoordinate(j,y);
        // then, delete grid[j][y]
        delete grid[j][y];
        grid[j].erase(grid[j].begin()+y); // remove tile from board
        grid[j].emplace_back(new Tile(new NoBlock(' ', j, y,0), ' '));
    }
    // update all coordinates above y  to subtract 1
    decrementCoords(y);
}

vector<int> Board::removeEmptyBlocks() {
    vector<int> scores;
    vector<Block*> newHasBlocks;
    for (int j = 0; j < hasBlocks.size(); j++) {
        if (hasBlocks[j]->howManyCoords() != 0) {
            newHasBlocks.emplace_back(hasBlocks[j]);
        } else {
            scores.emplace_back(hasBlocks[j]->getLevel());
            delete hasBlocks[j];
        }
    }
    hasBlocks = newHasBlocks;
    return scores;
}

void Board::drop(Block *block) {
    while (canDown(block)) {
        moveDown(block);
    }
    turnsWithoutClear++;
}

bool Board::canDown(Block *block) {
    if (!containBlock(block)) {
        return false;
    }
    Coordinate *bl = block->getBL();
    removeBlock(block);
    if (canPlace((bl->x), (bl->y)-1, block)) {
        placeBlock((bl->x), (bl->y), block);
        return true;
    }
    placeBlock((bl->x), (bl->y), block);
    return false;
}

void Board::moveDown(Block *block) { // assumes canDown()
    Coordinate *bl = block->getBL();
    removeBlock(block);
    placeBlock((bl->x), (bl->y)-1, block);
}

bool Board::canLeft(Block *block) {
    if (!containBlock(block)) {
        return false;
    }
    Coordinate *bl = block->getBL();
    removeBlock(block);
    if (canPlace((bl->x)-1, (bl->y), block)) {
        placeBlock((bl->x), (bl->y), block);
        return true;
    }
    placeBlock((bl->x), (bl->y), block);
    return false;
}

void Board::moveLeft(Block *block) { // assumes canDown()
    Coordinate *bl = block->getBL();
    removeBlock(block);
    placeBlock((bl->x)-1, (bl->y), block);
}

bool Board::canRight(Block *block) {
    if (!containBlock(block)) {
        return false;
    }
    Coordinate *bl = block->getBL();
    removeBlock(block);
    if (canPlace((bl->x)+1, (bl->y), block)) {
        placeBlock((bl->x), (bl->y), block);
        return true;
    }
    placeBlock((bl->x), (bl->y), block);
    return false;
}

void Board::moveRight(Block *block) { // assumes canDown()
    Coordinate *bl = block->getBL();
    removeBlock(block);
    placeBlock((bl->x)+1, (bl->y), block);
}

bool Board::containBlock(Block *block) {
    for (int i = 0; i < hasBlocks.size(); i++) {
        if (hasBlocks[i] == block) {
            return true;
        }
    }
    return false;
}

void Board::placeBlock(int x, int y, Block *block) { 
    block->updateCoordinates(x,y);
    hasBlocks.emplace_back(block);
    vector<Coordinate*> coords = block->getcList();
    for (int i = 0; i < coords.size(); i++) {
        grid[coords[i]->x][coords[i]->y]->changeNoBlock(block);
        grid[coords[i]->x][coords[i]->y]->updateType(block->getType());
    }
}