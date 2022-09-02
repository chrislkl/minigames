#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "interface.h"
using namespace std;

Interface::Interface(int row, int col, string file, int lvl, int highScore): intLevel{lvl}, file{file}, score{0}, specialAction{false}, blind{false}, heavy{false}, force{false}, heavySwitch{false}, endGame{false}, highScore{highScore} {
    board = new Board(row, col);
    if (intLevel == 0) {
        level = new Zero(file); 
    } else if (intLevel == 1) {
        level = new One();
    } else if (intLevel == 2) {
        level = new Two();
    } else if (intLevel == 3) {
        level = new Three();
    } else if (intLevel == 4) {
        level = new Four();
    }
    currBlock = level->createNextBlock();
    nextBlock = level->createNextBlock();
    board->placeBlock(0, row-1, currBlock);
}

Interface::~Interface() {
    delete board;
    delete nextBlock;
    delete level;
}

bool Interface::getEndGame() {
    return endGame;
}

int Interface::getRowTotal() {
    return board->getRowTotal();
}

int Interface::gethighScore() {
    return highScore;
}

int Interface::getScore() {
    return score;
}
void Interface::updateNoRandomLevel(string file) {
    if (intLevel == 3 || intLevel == 4) {
        level->addFile(file);
        level->updateNoRandom(true);
    }
}

void Interface::updateRandomLevel() {
    if (intLevel == 3 || intLevel == 4) {
        level->updateNoRandom(false);
    }
}

void Interface::printOverheadLine(int y, bool newLine) {
    if (y == board->getRowTotal()) {
        for (int i = 0; i < board->getCol(); i++) {
        cout << "-";
        }
        if (newLine) {
            cout << endl;
        } else {
            cout << "     ";
        }
        
    } else if (y == board->getRowTotal() + 1) {
        cout << "Score:";
        for (int i = 0; i < board->getCol()-7; i++) {
            cout << " ";
        }
        cout << score;
        if (newLine) {
            cout << endl;
        } else {
            cout << "     ";
        }
    } else if (y == board->getRowTotal() + 2) {
        cout << "Level:";
        for (int i = 0; i < board->getCol()-7; i++) {
            cout << " ";
        }
        cout << intLevel;
        if (newLine) {
            cout << endl;
        } else {
            cout << "     ";
        }
    } else if (y == board->getRowTotal() + 3) {
        cout << "Hi-Score:";
        for (int i = 0; i < board->getCol()-10; i++) {
            cout << " ";
        }
        cout << highScore;
        if (newLine) {
            cout << endl;
        } else {
            cout << "     ";
        }
    }
}

void Interface::printBoardInterfaceLine(int y, bool newLine) {
    // rowTotal to rowTotal+3 is overhead
    // 0 to rowTotal-1 is the board
    // -1 to -4 is next block section
    if (y >= board->getRowTotal()) {
        printOverheadLine(y, newLine);
    } else if (y >= 0) {
        board->printBoardLine(y, newLine, blind);
    } else if (y < 0) {
        printNextBlockLine(y, newLine);
    }
}

void Interface::printNextBlockLine(int y, bool newLine) {
    if (y == -1) {
        for (int i = 0; i < board->getCol(); i++) {
            cout << "-";
        }
        if (newLine) {
            cout << endl;
        } else {
            cout << "     ";
        }
    } else if (y == -2) {
        cout << "Next:      ";
        if (newLine) {
            cout << endl;
        } else {
            cout << "     ";
        }
    } else if (y == -3 || y == -4) {
        if (nextBlock->getType() == 'J') {
            if (y == -3) {
                cout << "J          ";
            } else {
                cout << "JJJ        ";
            }
        } else if (nextBlock->getType() == 'L') {
            if (y == -3) {
                cout << "  L        ";
            } else {
                cout << "LLL        ";
            }
        } else if (nextBlock->getType() == 'I') {
            if (y == -3) {
                cout << "IIII       ";
            } else {
                cout << "           ";
            }
        } else if (nextBlock->getType() == 'S') {
            if (y == -3) {
                cout << " SS        ";
            } else {
                cout << "SS         ";
            }
        } else if (nextBlock->getType() == 'Z') {
            if (y == -3) {
                cout << "ZZ         ";
            } else {
                cout << " ZZ        ";
            }
        } else if (nextBlock->getType() == 'O') {
            if (y == -3) {
                cout << "OO         ";
            } else {
                cout << "OO         ";
            }
        } else if (nextBlock->getType() == 'T') {
            if (y == -3) {
                cout << "TTT        ";
            } else {
                cout << " T         ";
            }
        }
        if (newLine) {
            cout << endl;
        } else {
            cout << "     ";
        }
    }
}

void Interface::activateForce(string blockName) {
    if (!force) {
        return;
    }
    board->removeBlock(currBlock);
    delete currBlock;
    if (blockName == "J") {
        currBlock = new JBlock('J', 0, 0, intLevel);
    } else if (blockName == "I") {
        currBlock = new IBlock('I', 0, 0, intLevel);
    } else if (blockName == "O") {
        currBlock = new OBlock('O', 0, 0, intLevel);
    } else if (blockName == "L") {
        currBlock = new LBlock('L', 0, 0, intLevel);
    } else if (blockName == "Z") {
        currBlock = new ZBlock('Z', 0, 0, intLevel);
    } else if (blockName == "S") {
        currBlock = new SBlock('S', 0, 0, intLevel);
    } else if (blockName == "T") {
        currBlock = new TBlock('T', 0, 0, intLevel);
    }

    if (board->canPlace(0, board->getRow()-1, currBlock)) {
        board->placeBlock(0, board->getRow()-1, currBlock); // if it cannot be placed, end game
    } 
    force = false;
}

void Interface::action(string act, int num) {
    if (act.substr(0,2) == "ri") {
        for (int i = 0; i < num; i++) {
            if (board->canRight(currBlock)) {
                board->moveRight(currBlock);
            }
            if (intLevel == 3 || intLevel == 4) {
                if (board->canDown(currBlock)) {
                    board->moveDown(currBlock);
                }
            }
        }
        if (heavy) {
            for (int i = 0; i < 2; i++) {
                if (board->canDown(currBlock)) {
                    board->moveDown(currBlock);
                } else {
                    action("drop", 1);
                }
            }
        }
    } else if (act.substr(0,3) == "lef") {
        for (int i = 0; i < num; i++) {
            if (board->canLeft(currBlock)) {
                board->moveLeft(currBlock);
            }
            if (intLevel == 3 || intLevel == 4) {
                if (board->canDown(currBlock)) {
                    board->moveDown(currBlock);
                }
            }
        }
        if (heavy) {
            for (int i = 0; i < 2; i++) {
                if (board->canDown(currBlock)) {
                    board->moveDown(currBlock);
                } else {
                    action("drop", 1);
                    heavySwitch = true;
                }
            }
        }
    } else if (act.substr(0,2) == "do") {
        for (int i = 0; i < num; i++) {
            if (board->canDown(currBlock)) {
                board->moveDown(currBlock);
            }
            if (intLevel == 3 || intLevel == 4) {
                if (board->canDown(currBlock)) {
                    board->moveDown(currBlock);
                }
            }
        }
    } else if (act.substr(0,2) == "cl") {
        for (int i = 0; i < num; i++) {
            board->rotate(currBlock, 1);
            if (intLevel == 3 || intLevel == 4) {
                if (board->canDown(currBlock)) {
                    board->moveDown(currBlock);
                }
            }
        }
    } else if (act.substr(0,2) == "co") {
        for (int i = 0; i < num; i++) {
            board->rotate(currBlock, -1);
            if (intLevel == 3 || intLevel == 4) {
                if (board->canDown(currBlock)) {
                    board->moveDown(currBlock);
                }
            }
        }
    } else if (act.substr(0,2) == "dr") {
        blind = false;
        heavy = false;
        board->drop(currBlock);
        currBlock = nextBlock;
        nextBlock = level->createNextBlock();
        int n = board->howManyFullLines();
        if (n != 0) {
            board->turnsWithoutClear = 0;
        } 
        if (n >= 2) {
            specialAction = true;
        }
        score += n * intLevel;
        while (n > 0) {
            board->removeLine(board->detectFullLines());
            vector<int> scoreLevels = board->removeEmptyBlocks();
            for (int i = 0; i < scoreLevels.size(); i++) {
                score += scoreLevels[i];
            }
            if (score > highScore) {
                highScore = score;
            }
            n = n-1;
        }
        if (intLevel == 4) {
            if (board->turnsWithoutClear == 5) {
                Onebyone *o = new Onebyone('*', 0, 0, intLevel);
                if (board->canPlace((board->getCol()/2), board->getRow()-1, o)) {
                    board->placeBlock((board->getCol()/2), board->getRow()-1, o); // if it cannot be placed, end game
                    board->drop(o);
                } else {
                    delete o;
                    endGame = true;
                    return;
                }
                board->turnsWithoutClear = 0;
            }
        }

        if (board->canPlace(0, board->getRow()-1, currBlock)) {
            board->placeBlock(0, board->getRow()-1, currBlock); // if it cannot be placed, end game
        } else {
            endGame = true;
            return;
        }
    } else if (act.substr(0,6) == "levelu") {
        for (int i = 0; i < num; i++) {
            updateLevel(1);
        }
    } else if (act.substr(0,6) == "leveld") {
        for (int i = 0; i < num; i++) {
            updateLevel(-1);
        }
    } else if (act.substr(0,1) == "n") {
        string s;
        cin >> s;
        updateNoRandomLevel(s);
    } else if (act.substr(0,2) == "ra") {
        updateRandomLevel();
    } else {
        throw logic_error{"a"};
    }
}

void Interface::updateLevel(int n) {
    if ((intLevel + n) >= 0 && (intLevel + n <= 4)) {
        intLevel += n;
        delete level;
        level = 0;
        if (intLevel == 0) {
            level = new Zero(file); 
        } else if (intLevel == 1) {
            level = new One();
        } else if (intLevel == 2) {
            level = new Two();
        } else if (intLevel == 3) {
            level = new Three();
        } else if (intLevel == 4) {
            board->turnsWithoutClear = 0;
            level = new Four();
        }
    }
}