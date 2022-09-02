#ifndef _IBLOCK_H_
#define _IBLOCK_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class IBlock: public Block {
    void DOrotate(int);
    public:
    IBlock(char, int, int, int);
    ~IBlock();
};

#endif
