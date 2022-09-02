#ifndef _LBLOCK_H_
#define _LBLOCK_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class LBlock: public Block {
    void DOrotate(int);
    public:
    LBlock(char, int, int, int);
    ~LBlock();
};

#endif
