#ifndef _ZBLOCK_H_
#define _ZBLOCK_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class ZBlock: public Block {
    void DOrotate(int);
    public:
    ZBlock(char, int, int, int);
    ~ZBlock();
};

#endif
