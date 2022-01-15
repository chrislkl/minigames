#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int realcol_num(col_num) {
    return (col_num - 1) * 2;
}

int checkEmpty(int row, int col, char TTT[3][5]) {
    return TTT[row][col] == '_';
}

int checkEdgeSpot(char sym, char TTT[3][5]) {
    return TTT[0][2] == sym || TTT[1][0] == sym || TTT[1][4] == sym || TTT[2][2] == sym;
}

int countSym(char sym, char line[]) {
    int counter = 0;
    for (int i = 0; i < 5; i++) {
        if (line[i] == sym) {
            counter++;
        }
    }
    return counter;
}

//finds empty spot in a line
int findEmpty(char line[]) {
    for (int i = 0; i < 5; i++) {
        if (line[i] == '_') {
            return i;
        }
    }
    return -1;
}

int checkWin(char sym, char TTT[3][5]) {
    char row[5];
    for (int i = 0; i < 3; i++) { // for rows
        for (int j = 0; j < 5; j++) {
            row[j] = TTT[i][j];
        }
        if (countSym(sym, row) == 3) {
            return 1;
        }
    }
    char col[5];
    for (int i = 0; i < 5; i++) { // for cols
        for (int j = 0; j < 3; j++) {
            col[j] = TTT[j][i];
        }
        if (countSym(sym, col) == 3) {
            return 1;
        }
    }
    char dia1[] = {TTT[0][0], ' ', TTT[1][2], ' ', TTT[2][4], '\0'};
    char dia2[] = {TTT[2][0], ' ', TTT[1][2], ' ', TTT[0][4], '\0'};
    if (countSym(sym, dia1) == 3) {
        return 1;
    }

    if (countSym(sym, dia2) == 3) {
        return 1;
    }
    return 0;
}
// implement emptyNumStop
void findEmptyBoard(char TTT[3][5], int emptyNumStop, int* emptySpot, int* totalEmptyNum) {
    emptySpot[0] = -1;
    emptySpot[1] = -1;
    *totalEmptyNum = 0;
    int counter = 0;

    for (int i = 0; i < 3; i++) { // for rows
        for (int j = 0; j < 5; j++) {
            if (counter == emptyNumStop) {
                i = 999;
                j = 999;
                *totalEmptyNum = counter;
                break;
            } else if (TTT[i][j] == '_') {
                emptySpot[0] = i;
                emptySpot[1] = j;
                counter += 1;
            }
        }
    }
    *totalEmptyNum = counter; 
}

void findThreat(char sym, char TTT[3][5], int* threat, int* threatNum) {
    char oppoSym;
    if (sym == 'X') {
        oppoSym = 'O';
    } else {
        oppoSym = 'X';
    }

    threat[0] = -1;
    threat[1] = -1;
    *threatNum = 0;

    char row[5];
    for (int i = 0; i < 3; i++) { // for rows
        for (int j = 0; j < 5; j++) {
            row[j] = TTT[i][j];
        }
        if (countSym(sym, row) == 2 && countSym(oppoSym, row) == 0) {
            threat[0] = i; // i is the row number
            threat[1] = findEmpty(row); //col number
            *threatNum += 1;
        }
    }

    char col[5];
    for (int i = 0; i < 5; i++) { // for cols
        for (int j = 0; j < 3; j++) {
            col[j] = TTT[j][i];
        }
        if (countSym(sym, col) == 2 && countSym(oppoSym, col) == 0) {
            threat[0] = findEmpty(col); //row number
            threat[1] = i; //col number
            *threatNum += 1;
        }
    }

    char dia1[] = {TTT[0][0], ' ', TTT[1][2], ' ', TTT[2][4], '\0'};
    char dia2[] = {TTT[2][0], ' ', TTT[1][2], ' ', TTT[0][4], '\0'};
    if (countSym(sym, dia1) == 2 && countSym(oppoSym, dia1) == 0) {
        threat[0] = findEmpty(dia1) / 2;
        threat[1] = findEmpty(dia1);
        *threatNum += 1;
    }

    if (countSym(sym, dia2) == 2 && countSym(oppoSym, dia2) == 0) {
        threat[0] = ((findEmpty(dia2) * -1) + 4) / 2;
        threat[1] = findEmpty(dia2);
        *threatNum += 1;
    }
}

void findFork(char sym, char TTT[3][5], int* forkSpot) {
    int emptySpot[2];
    int totalEmptyNum;
    int threatSpot[2];
    int threatNum;
    forkSpot[0] = -1;
    forkSpot[1] = -1;

    findEmptyBoard(TTT, 9, emptySpot, &totalEmptyNum);

    for (int i = totalEmptyNum; i > 0; i--) {
        findEmptyBoard(TTT, i, emptySpot, &totalEmptyNum);
        TTT[emptySpot[0]][emptySpot[1]] = sym;
        findThreat(sym, TTT, threatSpot, &threatNum);

        if (threatNum >= 2) {
            forkSpot[0] = emptySpot[0];
            forkSpot[1] = emptySpot[1];
        }
        TTT[emptySpot[0]][emptySpot[1]] = '_';
    }
}

int main()
{
    char TTT[3][5];
    initializeBoard(TTT);
    displayboard(TTT);

    char firstUser[10];

    do {
        printf("\n");
        printf("Who goes first? Player or Computer? \n");
        scanf("%s", &firstUser);

        if (strcmp(strlwr(firstUser), "player") == 0) {
            playerFirst(TTT);
        } else if (strcmp(strlwr(firstUser), "computer") == 0 || strcmp(strlwr(firstUser), "comp") == 0) {
            compFirst(TTT);
        } else {
            printf("Invalid User. Please Try Again. \n");
            printf("\n");
        }
    } while (strcmp(strlwr(firstUser), "player") != 0 && strcmp(strlwr(firstUser), "computer") != 0 && strcmp(strlwr(firstUser), "comp") != 0);

    return 0;
}

void compFirst(char TTT[3][5]) {
    // Computer Turn 1 :
    printf("\n");
    printf("Computer Turn 1: \n");
    printf("\n");
    TTT[0][0] = 'X';
    displayboard(TTT);

    for (int turn = 1; turn <= 4; turn
    ++){
        // Player Turn i :
        playerTurn(turn, 'O', TTT, TTT);
        displayboard(TTT);

        if(turn != 1) {
            compTurn(turn + 1, 'X', TTT, TTT);
        } else {
            printf("\n");
            printf("Computer Turn 2: \n");
            printf("\n");
            if (checkEdgeSpot('O', TTT) == 1  && checkEmpty(1, 2, TTT) == 1) {
                TTT[1][2] = 'X';
            } else if(TTT[1][2] == 'O') {
                TTT[0][2] = 'X';
            } else if(TTT[2][4] == 'O') {
                TTT[0][4] = 'X';
            } else if(TTT[0][4] == 'O') {
                TTT[1][0] = 'X';
            } else {
                TTT[0][2] = 'X';
            }
        }
        displayboard(TTT);

        if (checkWin('X', TTT) == 1) {
            printf("You Lost.\n");
            exit(main);
        } else if (turn == 4) {
            printf("\n");
            printf("Draw.");
            exit(main);
        }
    }
}

void playerFirst(char TTT[3][5]) {
    for (int turn = 1; turn <= 5; turn++) {
        // Player Turn i :
        playerTurn(turn, 'X', TTT, TTT);
        displayboard(TTT);

        if (turn == 5) {
            printf("\n");
            printf("Draw.");
            exit(main);
        } else if (turn != 1) {
            // Computer Turn i :
            compTurn(turn, 'O', TTT, TTT);
        } else {
            // Computer Turn 1 :
            printf("\n");
            printf("Computer Turn 1: \n");
            printf("\n");
            if (TTT[1][2] == '_') {
                TTT[1][2] = 'O';
            } else {
                TTT[0][0] = 'O';
            }
        }
        displayboard(TTT);

        // Checking if comp won
        if (checkWin('O', TTT) == 1) {
        printf("You Lost.\n");
        exit(main);
        }
    }
}

void compTurn(int turn, char sym, char TTT[3][5], char* newTTT[3][5]) {
    printf("\n");
    printf("Computer Turn %d: \n", turn);
    printf("\n");
    char oppoSym;
    if (sym == 'O') {
        oppoSym = 'X';
    } else {
        oppoSym = 'O';
    }

    int threatSpot[2];
    int threatNum; // number of threats (2 or more means theres a fork)
    findThreat(oppoSym, TTT, threatSpot, &threatNum);

    int winSpot[2];
    int winNum;
    findThreat(sym, TTT, winSpot, &winNum);

    int enemyForkSpot[2];
    findFork(oppoSym, TTT, enemyForkSpot);

    int winForkSpot[2];
    findFork(sym, TTT, winForkSpot);

    if (winNum >= 1) {
        TTT[winSpot[0]][winSpot[1]] = sym;
    } else if(threatNum >= 1) {
        TTT[threatSpot[0]][threatSpot[1]] = sym;
    } else if (winForkSpot[0] != -1) {
        TTT[winForkSpot[0]][winForkSpot[1]] = sym;
    } else if(enemyForkSpot[0] != -1) {
        TTT[enemyForkSpot[0]][enemyForkSpot[1]] = sym;
    } else {
        int emptySpot[2];
        int dummy;
        findEmptyBoard(TTT, 9, emptySpot, &dummy);
        TTT[emptySpot[0]][emptySpot[1]] = sym;
    }

    newTTT = TTT;
}

void playerTurn(int turn, char sym, char TTT[3][5], char* newTTT[3][5]) {
    int row_num;
    int col_num;
    do {
        printf("\n");
        printf("Player Turn %d:\n", turn);
        printf("Enter the Row Number (starting from 1): \n");
        scanf("%d", &row_num);
        printf("Enter the Column Number (starting from 1): \n");
        scanf("%d", &col_num);
        printf("\n");
        col_num = realcol_num(col_num);
        row_num = row_num - 1;

        if (checkEmpty (row_num, col_num, TTT) == 0) {
            occupied_spot();
        } else if (row_num > 3 || col_num > 4) {
            invalid_spot();
        }
    } while (checkEmpty(row_num, col_num, TTT) == 0 || row_num > 3 || col_num > 4);

    TTT[row_num][col_num] = sym;
    newTTT = TTT;
}


void initializeBoard(char TTT[3][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (j % 2 == 0) {
                TTT[i][j] = '_';
            } else {
                TTT[i][j] = ' ';
            }
        }
    }
}

void occupied_spot() {
    printf("Invalid Placement. This spot is already occupied.\n");
    printf("Please pick another spot.\n");
    printf("\n");
}

void invalid_spot() {
    printf("Invalid Placement. This spot does not exist.\n");
    printf("Please pick another spot.\n");
    printf("\n");
}

void displayboard(char TTT[3][5]) {
    printf("Current Board: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c", TTT[i][j]);
        }
        printf("\n");
    }
}
