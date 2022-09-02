#ifndef _SBLOCK_H_
#define _SBLOCK_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class SBlock: public Block {
    void DOrotate(int);
    public:
    SBlock(char, int, int, int);
    ~SBlock();
};

#endif
