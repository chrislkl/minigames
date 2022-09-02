#include <iostream>
#include <string>
#include "level.h"
using namespace std;

Block* Level::createNextBlock() {
    return DOcreateNextBlock();
}

void Level::updateNoRandom(bool r) {
    DOupdateNoRandom(r);
}
void Level::addFile(string file) {
    DOaddFile(file);
}

void Level::DOupdateNoRandom(bool r) {}

void Level::DOaddFile(string file) {}

Level::~Level() {}
