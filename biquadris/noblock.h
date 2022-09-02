#ifndef _NOBLOCK_H_
#define _NOBLOCK_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class NoBlock: public Block {
    void DOrotate(int);
    public:
    NoBlock(char, int, int, int);
    ~NoBlock();
};

#endif
