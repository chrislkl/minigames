#ifndef _THREE_H_
#define _THREE_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "level.h"

class Three: public Level {
    std::string file;
    Block* DOcreateNextBlock();
    std::ifstream iss;
    bool noRandom;
    void DOaddFile(std::string) override;
    void DOupdateNoRandom(bool) override;
    public:
    Three() {noRandom = false;}
    ~Three() {}
    
};

#endif
