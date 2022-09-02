#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "board.h"
#include "block.h"
#include "jblock.h"
#include "iblock.h"
#include "lblock.h"
#include "zblock.h"
#include "sblock.h"
#include "tblock.h"
#include "oblock.h"
#include "noblock.h"
#include "tile.h"
#include "interface.h"
#include "level.h"
#include "controller.h"

int main (int argc, char *argv[]) {
    int level = 0;
    string file1 = "biquadris_sequence1.txt";
    string file2 = "biquadris_sequence2.txt";
    int seed = 1; //default for random
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-scriptfile1") {
            file1 = argv[i+1];
            i++;
        } else if (string(argv[i]) == "-scriptfile2") {
            file1 = argv[i+1];
            i++;
        } else if (string(argv[i]) == "-startlevel") {
            istringstream iss{string(argv[i+1])};
            int p;
            iss >> p;
            level = p;
            i++;
        } else if (string(argv[i]) == "-seed") {
            istringstream iss{string(argv[i+1])};
            int p;
            iss >> p;
            seed = p;
            i++;
        }
    }
    srand(seed);
    
    Controller *c = new Controller(15,11, file1, file2, level);
    c->printController();
    string s;
    ifstream iss;
    bool is_sequence = false;
    while(cin >> s) {
        sequence:
        if (s == "sequence") {
            string file;
            cin >> file;
            iss.open(file);
            is_sequence = true;
        }
        if (is_sequence) {
            iss >> s;
            if (iss.eof()) {
                is_sequence = false;
                cin >> s;
            }
        }

        istringstream is2{s};
        int num = 1;
        if (!(is2 >> num)) {
            is2.clear();
            num = 1;
        }
        is2 >> s;
        try {
            if (s.substr(0,2) == "re") { //restart
                cout << endl;
                cout << "Game Over! New game starting ... " << endl;
                cout << endl;
                c->doEndGame();
                c->printController();
                if (is_sequence) {
                    goto sequence;
                } else {
                    continue;
                }
            }

            if (c->getHeavySwitch()) {
                c->falseHeavySwitch();
                c->switchTurn();
            }
            

            if (s.substr(0,2) == "dr") {
                c->action(s, num); 
                c->printController();
                if (c->getSpecialAction()) {
                    c->updateSpecialAction(false);
                    c->switchTurn();
                    //prompt user for special action
                    string a;
                    cout << "Special Action activated:" << endl;
                    cin >> a;
                    if (a == "blind") {
                        c->applyBlind();
                    } else if (a == "heavy") {
                        c->applyHeavy();
                    } else if (a == "force") {
                        c->applyForce();
                        cout << "Enter block to place on opponents screen:" << endl;
                        cin >> a;
                        c->doForce(a);
                    }
                    c->printController();
                } else {
                    c->switchTurn();
                }
            } else {
                c->action(s, num);
                c->printController(); 
            }
        }
        catch (logic_error var) {
            cout << "Invalid command. Please try again: " << endl;
        }


        c->switchTurn();
        if (c->getEndGame()) {
            cout << endl;
            cout << "Game Over! New game starting ... " << endl;
            cout << endl;
            c->doEndGame();
            c->printController();
        }
        c->switchTurn();
        if (is_sequence) {
            goto sequence;
        }
    }
    delete c;
}