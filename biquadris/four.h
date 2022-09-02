#ifndef _FOUR_H_
#define _FOUR_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "level.h"

class Four: public Level {
    std::string file;
    Block* DOcreateNextBlock();
    std::ifstream iss;
    bool noRandom;
    void DOaddFile(std::string) override;
    void DOupdateNoRandom(bool) override;
    public:
    Four() {noRandom = false;}
    ~Four() {}
};

#endif
