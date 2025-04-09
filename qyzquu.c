#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qyzquu.h"

void printRace(int playerPos, int opponentPos) {
    printf("\n");
    for (int i = 0; i < DISTANCE; i++) {
        if (i == playerPos) {
            printf("@");  
        } else if (i == opponentPos) {
            printf("0");  
        } else {
            printf("-");
        }
    }
    printf("\n");
}

int getPlayerMove() {
    int move;
    printf("\nenter your move (1-5 steps): \n");
    scanf("%d", &move);

    
    if (move < 1 || move > 5) {
        printf("invalid move! enter a number between 1 and 5\n");
        return getPlayerMove();  
    }
    return move;
}

int getOpponentMove() {
    return rand() % 10;  
}

void playQyzQuu() {
    srand(time(NULL));  

    printf("\nsalem! loading Qyz Quu...\n");
    printf("\nrules: you have a distance of 30 meters where you are horse racing \nwith the character of opposite gender. girl is running from and boy is catching. \ngirl has a head start advantage of 3 meters. \n \n*if boy catches girl, he can kiss her on the cheek\n \n*if girl escapes, she can hit him with a whip\n");

    int characterChoice;
    printf("\nchoose your character:\n");
    printf("\n1. boy (you chase the girl)\n");
    printf("\n2. girl (you run from the boy)\n");
    scanf("%d", &characterChoice);
    int playerPos, opponentPos;

    if (characterChoice == 1) {
        
        playerPos = 0;
        opponentPos = 3;
    } else if (characterChoice == 2) {
        
        playerPos = 3;      
        opponentPos = 0;
    } else {
        printf("\ninvalid character choice!\n");
        return;
    }
    
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
            printf("\ngame over! you caught the girl.\n");
            gameOver = 1;
            gameFinished = 1;
        }
        
        else if (girl && opponentPos >= playerPos) {
            printf("\ngame over! you got caught.\n");
            gameOver = 1;
            gameFinished = 1;
        }
        
        else if (playerPos >= DISTANCE || opponentPos >= DISTANCE) {
            gameOver = 1;
            gameFinished = 1;
            if (girl) {
                printf("\ncongratulations! you escaped to the finish line!\n");
            } else if (boy) {
                printf("\ntoo bad! the boy couldn't catch the girl in time.\n");
            }
        
        }

        if (playerPos >= DISTANCE || opponentPos >= DISTANCE) {
            gameOver = 1;
            gameFinished = 1;
        }
    }
}