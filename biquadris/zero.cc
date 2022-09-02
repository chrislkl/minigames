#include <iostream>
#include <string>
#include <fstream>
#include "zero.h"
using namespace std;

Zero::Zero(std::string file): file{file} {
    iss.open (file);
}

Block* Zero::DOcreateNextBlock() {
    string s;
    iss >> s;
    if (iss.eof()) {
        iss.close();
        iss.open (file);
        iss >> s;
    }
    if (s == "I") {
        IBlock *i = new IBlock('I', 0, 0, 0); //coordinates dont matter, gonna get moved anyways
        return i;
    } else if (s == "J") {
        JBlock *j = new JBlock('J', 0, 0, 0); 
        return j;
    } else if (s == "L") {
        LBlock *l = new LBlock('L', 0, 0, 0); 
        return l;
    } else if (s == "O") {
        OBlock *o = new OBlock('O', 0, 0, 0); 
        return o;
    } else if (s == "S") {
        SBlock *myS = new SBlock('S', 0, 0, 0); 
        return myS;
    } else if (s == "T") {
        TBlock *t = new TBlock('T', 0, 0, 0); 
        return t;
    } else if (s == "Z") {
        ZBlock *z = new ZBlock('Z', 0, 0, 0); 
        return z;
    } 
}
