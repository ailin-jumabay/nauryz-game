#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qyzquu.h"

void printRace(int playerPos, int opponentPos) {
    for (int i = 0; i < DISTANCE; i++) {
        if (i == playerPos) {
            printf("@");  // Игрок
        } else if (i == opponentPos) {
            printf("0");  // Противник
        } else {
            printf("-");
        }
    }
    printf("\n");
}

int getPlayerMove() {
    int move;
    printf("enter your move (1-5 steps): ");
    scanf("%d", &move);

    
    if (move <= 1 || move >= 5) {
        printf("Invalid move! Please enter a number between 1 and 5.\n");
        return getPlayerMove();  
    }
    return move;
}

int getOpponentMove() {
    return rand() % 10;  
}

void playQyzQuu() {
    srand(time(NULL));  

    printf("salem! loading Qyz Quu...\n");

    int characterChoice;
    printf("Choose your character:\n");
    printf("1. Boy (You chase the girl)\n");
    printf("2. Girl (You run from the boy)\n");
    scanf("%d", &characterChoice);

    int playerPos = 0;   
    int opponentPos = 0; 
    int gameOver = 0;
    extern int gameFinished;
    
    
    int boy = (characterChoice == 1);  
    int girl = (characterChoice == 2); 

    while (!gameOver) {
        printRace(playerPos, opponentPos); 

        
        int playerMove = getPlayerMove();
        playerPos += playerMove;  

        
        int opponentMove = getOpponentMove();
        opponentPos += opponentMove;  

        
        if (boy && playerPos >= opponentPos) {  
            gameOver = 1;
            printf("Game Over! The boy caught the girl.\n");
            gameFinished = 1;
        } else if (girl && opponentPos >= playerPos) {  
            gameOver = 1;
            printf("Congratulations! The girl escaped from the boy. \n");
            gameFinished = 1;
        }

        if (playerPos >= DISTANCE || opponentPos >= DISTANCE) {
            gameOver = 1;
            gameFinished = 1;
        }
    }
}