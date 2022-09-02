#ifndef _OBLOCK_H_
#define _OBLOCK_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class OBlock: public Block {
    void DOrotate(int);
    public:
    OBlock(char, int, int, int);
    ~OBlock();
};

#endif
