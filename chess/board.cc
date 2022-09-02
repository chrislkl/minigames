#include <iostream>
#include <string>
#include <vector>
#include "board.h"
using namespace std;

Board::Board(bool setup) {
    col = 8;
    row = 8;
    if (setup) {
        for (int i = 0; i < col; i++) {
            vector<Piece*> v1;
            for (int j = 0; j < row; j++) {
                if ((j + i) % 2 == 0) {
                    NoPiece *np = new NoPiece('_', j, i, "none");
                    v1.emplace_back(np);
                } else {
                    NoPiece *np = new NoPiece(' ', j, i, "none");
                    v1.emplace_back(np);
                }
            }
            grid.emplace_back(v1);
        }
    } else {
        vector<Piece*> v1;
        Rook *R1 = new Rook('R', 0, 0, "white");
        v1.emplace_back(R1);
        Pawn *P1 = new Pawn('P', 0, 1, "white");
        v1.emplace_back(P1);
        NoPiece *NP1 = new NoPiece('_', 0, 2, "none");
        v1.emplace_back(NP1);
        NoPiece *NP2 = new NoPiece(' ', 0, 3, "none");
        v1.emplace_back(NP2);
        NoPiece *NP3 = new NoPiece('_', 0, 4, "none");
        v1.emplace_back(NP3);
        NoPiece *NP4 = new NoPiece(' ', 0, 5, "none");
        v1.emplace_back(NP4);
        Pawn *P2 = new Pawn('p', 0, 6, "black");
        v1.emplace_back(P2);
        Rook *R2 = new Rook('r', 0, 7, "black");
        v1.emplace_back(R2);
        grid.emplace_back(v1);

        vector<Piece*> v2;
        Knight *N1 = new Knight('N', 1, 0, "white");
        v2.emplace_back(N1);
        Pawn *P3 = new Pawn('P', 1, 1, "white");
        v2.emplace_back(P3);
        NoPiece *NP5 = new NoPiece(' ', 1, 2, "none");
        v2.emplace_back(NP5);
        NoPiece *NP6 = new NoPiece('_', 1, 3, "none");
        v2.emplace_back(NP6);
        NoPiece *NP7 = new NoPiece(' ', 1, 4, "none");
        v2.emplace_back(NP7);
        NoPiece *NP8 = new NoPiece('_', 1, 5, "none");
        v2.emplace_back(NP8);
        Pawn *P4 = new Pawn('p', 1, 6, "black");
        v2.emplace_back(P4);
        Knight *N2 = new Knight('n', 1, 7, "black");
        v2.emplace_back(N2);
        grid.emplace_back(v2);

        vector<Piece*> v3;
        Bishop *B1 = new Bishop('B', 2, 0, "white");
        v3.emplace_back(B1);
        Pawn *P5 = new Pawn('P', 2, 1, "white");
        v3.emplace_back(P5);
        NoPiece *NP9 = new NoPiece('_', 2, 2, "none");
        v3.emplace_back(NP9);
        NoPiece *NP10 = new NoPiece(' ', 2, 3, "none");
        v3.emplace_back(NP10);
        NoPiece *NP11 = new NoPiece('_', 2, 4, "none");
        v3.emplace_back(NP11);
        NoPiece *NP12 = new NoPiece(' ', 2, 5, "none");
        v3.emplace_back(NP12);
        Pawn *P6 = new Pawn('p', 2, 6, "black");
        v3.emplace_back(P6);
        Bishop *B2 = new Bishop('b', 2, 7, "black");
        v3.emplace_back(B2);
        grid.emplace_back(v3);

        vector<Piece*> v4;
        Queen *Q1 = new Queen('Q', 3, 0, "white");
        v4.emplace_back(Q1);
        Pawn *P7 = new Pawn('P', 3, 1, "white");
        v4.emplace_back(P7);
        NoPiece *NP13 = new NoPiece(' ', 3, 2, "none");
        v4.emplace_back(NP13);
        NoPiece *NP14 = new NoPiece('_', 3, 3, "none");
        v4.emplace_back(NP14);
        NoPiece *NP15 = new NoPiece(' ', 3, 4, "none");
        v4.emplace_back(NP15);
        NoPiece *NP16 = new NoPiece('_', 3, 5, "none");
        v4.emplace_back(NP16);
        Pawn *P8 = new Pawn('p', 3, 6, "black");
        v4.emplace_back(P8);
        Queen *Q2 = new Queen('q', 3, 7, "black");
        v4.emplace_back(Q2);
        grid.emplace_back(v4);

        vector<Piece*> v5;
        King *K1 = new King('K', 4, 0, "white");
        v5.emplace_back(K1);
        Pawn *P9 = new Pawn('P', 4, 1, "white");
        v5.emplace_back(P9);
        NoPiece *NP17 = new NoPiece('_', 4, 2, "none");
        v5.emplace_back(NP17);
        NoPiece *NP18 = new NoPiece(' ', 4, 3, "none");
        v5.emplace_back(NP18);
        NoPiece *NP19 = new NoPiece('_', 4, 4, "none");
        v5.emplace_back(NP19);
        NoPiece *NP20 = new NoPiece(' ', 4, 5, "none");
        v5.emplace_back(NP20);
        Pawn *P10 = new Pawn('p', 4, 6, "black");
        v5.emplace_back(P10);
        King *K2 = new King('k', 4, 7, "black");
        v5.emplace_back(K2);
        grid.emplace_back(v5);

        vector<Piece*> v6;
        Bishop *B3 = new Bishop('B', 5, 0, "white");
        v6.emplace_back(B3);
        Pawn *P11 = new Pawn('P', 5, 1, "white");
        v6.emplace_back(P11);
        NoPiece *NP21 = new NoPiece(' ', 5, 2, "none");
        v6.emplace_back(NP21);
        NoPiece *NP22 = new NoPiece('_', 5, 3, "none");
        v6.emplace_back(NP22);
        NoPiece *NP23 = new NoPiece(' ', 5, 4, "none");
        v6.emplace_back(NP23);
        NoPiece *NP24 = new NoPiece('_', 5, 5, "none");
        v6.emplace_back(NP24);
        Pawn *P12 = new Pawn('p', 5, 6, "black");
        v6.emplace_back(P12);
        Bishop *B4 = new Bishop('b', 5, 7, "black");
        v6.emplace_back(B4);
        grid.emplace_back(v6);

        vector<Piece*> v7;
        Knight *N3 = new Knight('N', 6, 0, "white");
        v7.emplace_back(N3);
        Pawn *P13 = new Pawn('P', 6, 1, "white");
        v7.emplace_back(P13);
        NoPiece *NP25 = new NoPiece('_', 6, 2, "none");
        v7.emplace_back(NP25);
        NoPiece *NP26 = new NoPiece(' ', 6, 3, "none");
        v7.emplace_back(NP26);
        NoPiece *NP27 = new NoPiece('_', 6, 4, "none");
        v7.emplace_back(NP27);
        NoPiece *NP28 = new NoPiece(' ', 6, 5, "none");
        v7.emplace_back(NP28);
        Pawn *P14 = new Pawn('p', 6, 6, "black");
        v7.emplace_back(P14);
        Knight *N4 = new Knight('n', 6, 7, "black");
        v7.emplace_back(N4);
        grid.emplace_back(v7);

        vector<Piece*> v8;
        Rook *R3 = new Rook('R', 7, 0, "white");
        v8.emplace_back(R3);
        Pawn *P15 = new Pawn('P', 7, 1, "white");
        v8.emplace_back(P15);
        NoPiece *NP29 = new NoPiece(' ', 7, 2, "none");
        v8.emplace_back(NP29);
        NoPiece *NP30 = new NoPiece('_', 7, 3, "none");
        v8.emplace_back(NP30);
        NoPiece *NP31 = new NoPiece(' ', 7, 4, "none");
        v8.emplace_back(NP31);
        NoPiece *NP32 = new NoPiece('_', 7, 5, "none");
        v8.emplace_back(NP32);
        Pawn *P16 = new Pawn('p', 7, 6, "black");
        v8.emplace_back(P16);
        Rook *R4 = new Rook('r', 7, 7, "black");
        v8.emplace_back(R4);
        grid.emplace_back(v8);
    }
}

bool Board::twoKingsExist() {
    bool whiteKing = false;
    bool blackKing = false;
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (grid[j][i]->getName() == 'k') {
                if (!blackKing) {
                    blackKing = true;
                } else if (blackKing) {
                    return false;
                }
            } else if (grid[j][i]->getName() == 'K') {
                if (!whiteKing) {
                    whiteKing = true;
                } else if (whiteKing) {
                    return false;
                }
            }
        }
    }
    return blackKing && whiteKing;
}

bool Board::noPawnsFirstandLastRow() {
    bool firstRow = true;
    bool lastRow = true;
    
    for (int j = 0; j < getCol(); j++) {
        if (grid[j][0]->getName() == 'p' || grid[j][0]->getName() == 'P') {
            firstRow = false;
        } 
        if (grid[j][7]->getName() == 'p' || grid[j][7]->getName() == 'P') {
            lastRow = false;
        }
    }
    return firstRow && lastRow;
}

void Board::place(char name, int x, int y, string player) { // remember to check if its a valid position
    if (x < 0 || x >= 8 || y < 0 || y >= 8) { //throw
        throw logic_error {"a"};
    }

    delete grid[x][y];
    if (name == 'r' || name == 'R') {
        grid[x][y] = new Rook(name, x, y, player);
    } else if (name == 'n' || name == 'N') {
        grid[x][y] = new Knight(name, x, y, player);
    } else if (name == 'b' || name == 'B') {
        grid[x][y] = new Bishop(name, x, y, player);
    } else if (name == 'q' || name == 'Q') {
        grid[x][y] = new Queen(name, x, y, player);
    } else if (name == 'k' || name == 'K') {
        grid[x][y] = new King(name, x, y, player);
    } else if (name == 'p' || name == 'P') {
        grid[x][y] = new Pawn(name, x, y, player);
    } else {
        throw logic_error {"a"};
    }
}

void Board::remove(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) { //throw
        throw logic_error {"a"};
    } 

    delete grid[x][y];
    if ((x + y) % 2 == 0) {
        grid[x][y] = new NoPiece('_', x, y, "none");
    } else {
        grid[x][y] = new NoPiece(' ', x, y, "none");
    }
}

bool Board::kingValidMoveExists(string player) {
    bool NW = checkValidMove(locateKingX(player), locateKingY(player), locateKingX(player)-1, locateKingY(player)+1);
    bool N = checkValidMove(locateKingX(player), locateKingY(player), locateKingX(player), locateKingY(player)+1);
    bool NE = checkValidMove(locateKingX(player), locateKingY(player), locateKingX(player)+1, locateKingY(player)+1);
    bool E = checkValidMove(locateKingX(player), locateKingY(player), locateKingX(player)+1, locateKingY(player));
    bool SE = checkValidMove(locateKingX(player), locateKingY(player), locateKingX(player)+1, locateKingY(player)-1);
    bool S = checkValidMove(locateKingX(player), locateKingY(player), locateKingX(player), locateKingY(player)-1);
    bool SW = checkValidMove(locateKingX(player), locateKingY(player), locateKingX(player)-1, locateKingY(player)-1);
    bool W = checkValidMove(locateKingX(player), locateKingY(player), locateKingX(player)-1, locateKingY(player));
    return (NW || N || NE || E || SE || S || SW || W);
}

bool Board::checkValidMove(int fromX, int fromY, int toX, int toY) {
    if (grid[fromX][fromY]->checkValidMove(toX, toY)) { // checks simply for valid move without knowing board state
        if (grid[toX][toY]->getPlayer() != grid[fromX][fromY]->getPlayer()) { // checks if the spot is a non friendly piece
            if (grid[fromX][fromY]->getName() == 'k' || grid[fromX][fromY]->getName() == 'K') {
                if (grid[fromX][fromY]->checkMoveMakesThreatened(toX, toY, this)) { // if piece is a king, does moving it make it threatened?
                    return false;
                } else {
                    return true;
                }
            }
            if (!(grid[fromX][fromY]->checkBlockingPiece(toX, toY, this))) { // checks no blocking pieces
                if (!(grid[fromX][fromY]->isPinned(this))) { //checks if its not pinned
                    return true; 
                } else { // if it is pinned, does moving it to toX, toY make it unpinned?
                    if (grid[fromX][fromY]->checkMoveRemovesPin(toX, toY, this)) {
                        return true;
                    }
                }
            }
        }
    }
    if (grid[fromX][fromY]->getName() == 'p' || grid[fromX][fromY]->getName() == 'P') {
        if (grid[fromX][fromY]->checkCaptureMove(toX, toY, this)) {
            if (!(grid[fromX][fromY]->isPinned(this))) { //checks if its pinned
                    return true;
            } else {
                if (grid[fromX][fromY]->checkMoveRemovesPin(toX, toY, this)) {
                    return true;
                }
            }
        }
    }
    // check if pinned
    return false;
}

void Board::move(int fromX, int fromY, int toX, int toY) {
    if (!checkValidMove(fromX, fromY, toX, toY)) {
        throw std::logic_error {"1"};
    } 
    delete grid[toX][toY];
    grid[toX][toY] = grid[fromX][fromY];
    grid[toX][toY]->updateX(toX);
    grid[toX][toY]->updateY(toY);
    if ((fromX + fromY) % 2 == 0) {
        grid[fromX][fromY] = new NoPiece('_', fromX, fromY, "none");
    } else {
        grid[fromX][fromY] = new NoPiece(' ', fromX, fromY, "none");
    }
    if (grid[toX][toY]->getName() == 'p' || grid[toX][toY]->getName() == 'P') {
        grid[toX][toY]->updatehasMoved(true);
    }
}

void Board::checkPawnPromotion(int x, int y) {
    if (grid[x][y]->getName() != 'p' && grid[x][y]->getName() != 'P') {
        return;
    }
    if (y == 7 || y == 0) {
        cout << "Your pawn is being promoted. Enter the name of the piece to replace it: (queen, knight, bishop, rook) " << endl;
        string name;
        cin >> name;
        if (grid[x][y]->getPlayer() == "white") {
            if (name == "queen") {
                place('Q', x, y, "white");
            } else if (name == "knight") {
                place('K', x, y, "white");
            } else if (name == "bishop") {
                place('B', x, y, "white");
            } else if (name == "rook") {
                place('R', x, y, "white");
            } 
        } else if (grid[x][y]->getPlayer() == "black") {
            if (name == "queen") {
                place('q', x, y, "black");
            } else if (name == "knight") {
                place('k', x, y, "black");
            } else if (name == "bishop") {
                place('b', x, y, "black");
            } else if (name == "rook") {
                place('r', x, y, "black");
            } 
        }
    }
}

void Board::promotePawnComp(int x, int y) {
    if (grid[x][y]->getName() != 'p' && grid[x][y]->getName() != 'P') {
        return;
    }
    if (y == 7 || y == 0) {
        if (grid[x][y]->getPlayer() == "white") {

            place('Q', x, y, "white");

        } else if (grid[x][y]->getPlayer() == "black") {

            place('q', x, y, "black");

        }
    }
}

string Board::checkCheckmate(string player) {
    if (player == "white") {
        if ((!(kingValidMoveExists("white"))) && (isThreatened(locateKingX("white"),locateKingY("white")))) {
            vector <int> threat = grid[locateKingX("white")][locateKingY("white")]->findThreatening(this);
            int threatX = threat[0];
            int threatY = threat[1];
            if (!checkPreventThreat(locateKingX("white"), locateKingY("white"), threatX, threatY)) {
                return "white";
            }
        }
        return "none";
    } else {
        if ((!(kingValidMoveExists("black"))) && (isThreatened(locateKingX("black"),locateKingY("black")))) {
            vector <int> threat = grid[locateKingX("black")][locateKingY("black")]->findThreatening(this);
            int threatX = threat[0];
            int threatY = threat[1];
            if (!checkPreventThreat(locateKingX("black"), locateKingY("black"), threatX, threatY)) {
                return "black";
            }
        }
        return "none";
    }
}

bool Board::checkStalemate(string player) {
    if (isThreatened(locateKingX(player),locateKingY(player))) {
        return false;
    }
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (grid[j][i]->getPlayer() == player) {
                vector<int> place;
                place = getRandomLegalMove(j, i);
                if (place[0] != -1) { // no legal moves
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> Board::getRandomThreatenedPiece(string player) {
    vector<int> place;
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if ((grid[j][i]->getPlayer() == player) && (grid[j][i]->isThreatened(this))) {
                place.emplace_back(j);
                place.emplace_back(i);
                return place;
            }
        }
    }
    place.emplace_back(-1); // if no threatened piece
    place.emplace_back(-1);
    return place;
}

vector<int> Board::getRandomAvoidCaptureMove(int x, int y) {
    vector<int> place;
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (checkValidMove(x,y,j,i) && !grid[x][y]->checkMoveMakesThreatened(j,i, this)) {
                place.emplace_back(j);
                place.emplace_back(i);
                return place;
            }
        }
    }
    place.emplace_back(-1); // if no avoid capture move
    place.emplace_back(-1);
    return place;
}

vector<int> Board::getRandomLegalMove(int x, int y) {
    vector<int> place;
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (checkValidMove(x,y,j,i)) {
                place.emplace_back(j);
                place.emplace_back(i);
                return place;
            }
        }
    }
    place.emplace_back(-1); // if no legal move
    place.emplace_back(-1);
    return place;
}

vector<int> Board::getRandomCaptureMoveofPiece(int x, int y) {
    vector<int> place;
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (checkValidMove(x,y,j,i) && (grid[j][i]->getPlayer() != grid[x][y]->getPlayer()) && (grid[j][i]->getPlayer() != "none")) {
                place.emplace_back(j);
                place.emplace_back(i);
                return place;
            }
        }
    }
    place.emplace_back(-1); // if no legal move
    place.emplace_back(-1);
    return place;
}

vector<int> Board::getRandomCaptureMove(string player) {
    vector<int> place;
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (grid[j][i]->getPlayer() == player) {
                place = getRandomCaptureMoveofPiece(j, i);
                int x = place[0];
                int y = place[1];
                if (x != -1) {
                    place.emplace_back(j);
                    place.emplace_back(i);
                    return place;
                }
            }
        }
    }
    return place;
}
vector<int> Board::getRandomCheckMoveofPiece(int x, int y) {
    vector<int> place;
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (checkValidMove(x,y,j,i) && grid[x][y]->checkMoveMakesCheck(j,i, this)) {
                place.emplace_back(j);
                place.emplace_back(i);
                return place;
            }
        }
    }
    place.emplace_back(-1); // if no legal move
    place.emplace_back(-1);
    return place;
}

vector<int> Board::getRandomCheckMove(string player) {
    vector<int> place;
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (grid[j][i]->getPlayer() == player) {
                place = getRandomCheckMoveofPiece(j, i);
                int x = place[0];
                int y = place[1];
                if (x != -1) { 
                    place.emplace_back(j);
                    place.emplace_back(i);
                    return place;
                }
            }
        }
    }
    return place;
}

vector<int> Board::getPathCoords(int fromX, int fromY, int toX, int toY) {
    return grid[fromX][fromY]->getPathCoords(toX,toY, this);
}

void Board::printBoard() {
    for (int i = col-1; i >= 0; i--) { // grid[0][0] at the bottom left 
        cout << i+1 << " ";
        for (int j = 0; j < row; j++) {// j = row, i = col, starts at (0,7) to (7,7) then (0,6) to (7,6) until (0,0) to (8,0)
            grid[j][i]->printPiece();
        }
        cout << endl;
    }
    cout << endl;
    cout << "  abcdefgh" << endl;
}

bool Board::checkPreventThreat(int x, int y, int threatX, int threatY) {
    vector<int> path = grid[threatX][threatY]->getPathCoords(x,y, this);
    for (int i = 0; i < path.size(); i = i + 2) {
        int pathX = path[i];
        int pathY = path[i+1];
        for (int h = 0; h < getRow(); h++) {
            for (int j = 0; j < getCol(); j++) {
                if ((getPlayerAt(j, h) == getPlayerAt(x,y)) && (getPlayerAt(j, h) != "none")) {
                    if (j == x && h == y) {
                        continue;
                    }
                    if (checkValidMove(j, h, pathX, pathY)) {
                        return true;
                    } 
                }
            }
        }
    }
    return false;
}

int Board::locateKingX(string player) {
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (((grid[j][i]->getName() == 'k') || (grid[j][i]->getName() == 'K')) && (getPlayerAt(j, i) == player)) {
                return j;
            }
        }
    }
}

int Board::locateKingY(string player) {
    for (int i = 0; i < getRow(); i++) {
        for (int j = 0; j < getCol(); j++) {
            if (((grid[j][i]->getName() == 'k') || (grid[j][i]->getName() == 'K')) && (getPlayerAt(j, i) == player)) {
                return i;
            }
        }
    }
}

string Board::getPlayerAt(int x, int y) {
    return grid[x][y]->getPlayer();
}

Board::~Board() {
    for (int i = col-1; i >= 0; i--) { // grid[0][0] at the bottom left 
        for (int j = 0; j < row; j++) {// j = row, i = col, starts at (0,7) to (7,7) then (0,6) to (7,6) until (0,0) to (8,0)
            delete grid[j][i];
        }
    }
}

bool Board::isPinned(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) { 
        return false;
    } 
    return grid[x][y]->isPinned(this);
}

bool Board::isThreatened(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) { 
        return false;
    } 
    return grid[x][y]->isThreatened(this);
}

int Board::getRow() {
    return row;
}

int Board::getCol() {
    return col;
}

string coordsToString(int x, int y) {
    char xc = '0'+ x + 48;
    char yc = '0'+ y;
    string xs(1, xc);
    string ys(1, yc);
    return xs + ys;
}

