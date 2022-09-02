#ifndef _ZERO_H_
#define _ZERO_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "level.h"

class Zero: public Level {
    std::string file;
    Block* DOcreateNextBlock();
    std::ifstream iss;
    public:
    Zero(std::string);
    ~Zero() {}
};

#endif
