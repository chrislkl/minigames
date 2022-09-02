#include <iostream>
#include <string>
#include <fstream>
#include "three.h"
using namespace std;

Block* Three::DOcreateNextBlock() {
    if (!noRandom) {
        int x = rand() % 9;

        if (x == 0 || x == 7) {
            SBlock *myS = new SBlock('S', 0, 0, 3); 
            return myS;
        } else if (x == 1 || x == 8) {
            ZBlock *z = new ZBlock('Z', 0, 0, 3); 
            return z;
        } else if (x == 2) {
            IBlock *i = new IBlock('I', 0, 0, 3); //coordinates dont matter, gonna get moved anyways
            return i;
        } else if (x == 3) {
            LBlock *l = new LBlock('L', 0, 0, 3); 
            return l;
        } else if (x == 4) {
            OBlock *o = new OBlock('O', 0, 0, 3); 
            return o;
        } else if (x == 5) {
            TBlock *t = new TBlock('T', 0, 0, 3); 
            return t;
        } else if (x == 6) {
            JBlock *j = new JBlock('J', 0, 0, 3); 
            return j;
        }
    } else {
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
}

void Three::DOaddFile(string file) {
    this->file = file;
}

void Three::DOupdateNoRandom(bool r) {
    if (r) {
        iss.open (file);
    } else {
        iss.close();
    }
    noRandom = r;
}