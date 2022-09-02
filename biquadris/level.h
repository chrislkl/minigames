#ifndef _LEVEL_H_
#define _LEVEL_H_
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "block.h"
#include "jblock.h"
#include "iblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"


class Level {
    virtual Block* DOcreateNextBlock() = 0;
    virtual void DOaddFile(std::string);
    virtual void DOupdateNoRandom(bool);
    public:
    Level() {}
    virtual ~Level() = 0;

    void addFile(std::string);
    void updateNoRandom(bool);
    Block* createNextBlock();
};

#endif
