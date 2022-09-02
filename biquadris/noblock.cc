#include <iostream>
#include <string>
#include "noblock.h"
#include "board.h"
using namespace std;

NoBlock::NoBlock(char type, int x, int y, int level): Block(type, x, y, level) {}

NoBlock::~NoBlock() { delete BLcoords;};

void NoBlock::DOrotate(int n) {

}