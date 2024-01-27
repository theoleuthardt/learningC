#ifndef EXAMTEMPLATE_LIST_H
#define EXAMTEMPLATE_LIST_H

struct gameData{
    char choice1[10];
    char choice2[10];
    int winner;                     // Spielerzahl als Ergebnis (1 oder 2, 0 = unentschieden)
    struct gameData *next;
};

void addGame(char choice1[10], char choice2[10], int winner);
int size();
void *getGameData(int index);
int countGames();
void printGameData();
void statistics();


#endif //EXAMTEMPLATE_LIST_H
