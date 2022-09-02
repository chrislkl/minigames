#ifndef _ONEBYONE_H_
#define _ONEBYONE_H_
#include <iostream>
#include <string>
#include <vector>
#include "block.h"

class Onebyone: public Block {
    void DOrotate(int);
    public:
    Onebyone(char, int, int, int);
    ~Onebyone();
};

#endif