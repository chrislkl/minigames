#include <iostream>
#include <string>
#include "tile.h"
using namespace std;

Tile::Tile(Block *block, char type): block{block}, type{type} {}

char Tile::getType() {
    return type;
}

void Tile::changeNoBlock(Block *block) {
    delete this->block;
    this->block = block;
}

void Tile::changeBlock(Block *block) {
    this->block = block;
}

Block* Tile::getBlock() {
    return block;
}

void Tile::updateType(char type) {
    this->type = type;
}

Tile::~Tile() {
    if (type == ' ') {
        delete block;
    }
}