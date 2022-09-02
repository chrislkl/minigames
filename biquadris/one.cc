#include <iostream>
#include <string>
#include "one.h"
using namespace std;

Block* One::DOcreateNextBlock() {
    int x = rand() % 12;

    if (x == 0) {
        SBlock *myS = new SBlock('S', 0, 0, 1); 
        return myS;
    } else if (x == 1) {
        ZBlock *z = new ZBlock('Z', 0, 0, 1); 
        return z;
    } else if (x == 2 || x == 3) {
        IBlock *i = new IBlock('I', 0, 0, 1); //coordinates dont matter, gonna get moved anyways
        return i;
    } else if (x == 4 || x == 5) {
        LBlock *l = new LBlock('L', 0, 0, 1); 
        return l;
    } else if (x == 6 || x == 7) {
        OBlock *o = new OBlock('O', 0, 0, 1); 
        return o;
    } else if (x == 8 || x == 9) {
        TBlock *t = new TBlock('T', 0, 0, 1); 
        return t;
    } else if (x == 10 || x == 11) {
        JBlock *j = new JBlock('J', 0, 0, 1); 
        return j;
    }
}