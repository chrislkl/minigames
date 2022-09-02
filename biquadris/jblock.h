#ifndef _JBLOCK_H_
#define _JBLOCK_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class JBlock: public Block {
    void DOrotate(int);
    public:
    JBlock(char, int, int, int);
    ~JBlock();
};

#endif
