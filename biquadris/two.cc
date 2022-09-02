#include <iostream>
#include <string>
#include "two.h"
using namespace std;

Block* Two::DOcreateNextBlock() {
    int x = rand() % 7;
    if (x == 0) {
        SBlock *myS = new SBlock('S', 0, 0, 2); 
        return myS;
    } else if (x == 1) {
        ZBlock *z = new ZBlock('Z', 0, 0, 2); 
        return z;
    } else if (x == 2) {
        IBlock *i = new IBlock('I', 0, 0, 2); //coordinates dont matter, gonna get moved anyways
        return i;
    } else if (x == 3) {
        LBlock *l = new LBlock('L', 0, 0, 2); 
        return l;
    } else if (x == 4) {
        OBlock *o = new OBlock('O', 0, 0, 2); 
        return o;
    } else if (x == 5) {
        TBlock *t = new TBlock('T', 0, 0, 2); 
        return t;
    } else if (x == 6) {
        JBlock *j = new JBlock('J', 0, 0, 2); 
        return j;
    }
}