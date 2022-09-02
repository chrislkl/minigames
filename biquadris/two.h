#ifndef _TWO_H_
#define _TWO_H_
#include <iostream>
#include <string>
#include <vector>
#include "level.h"

class Two: public Level {
    Block* DOcreateNextBlock();
    public:
    Two() {}
    ~Two() {}
};

#endif
