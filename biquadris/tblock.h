#ifndef _TBLOCK_H_
#define _TBLOCK_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class TBlock: public Block {
    void DOrotate(int);
    public:
    TBlock(char, int, int, int);
    ~TBlock();
};

#endif
