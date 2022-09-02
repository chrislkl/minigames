#ifndef _ONE_H_
#define _ONE_H_
#include <iostream>
#include <string>
#include <vector>
#include "level.h"

class One: public Level {
    Block* DOcreateNextBlock();
    public:
    One() {}
    ~One() {}
};

#endif
