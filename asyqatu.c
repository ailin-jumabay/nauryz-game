#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "asyqatu.h"

void printField(char field[]) {
    for (int i = 0; i < FIELD_SIZE; i++) {
        printf("%c ", field[i]);
    }
    printf("\n");
}

int throwAsyq(int target, int power) {
    int hitChance, maxDeviation;

    if (power == 1) {
        hitChance = HIT_CHANCE_1;
        maxDeviation = 1;
    } else if (power == 2) {
        hitChance = HIT_CHANCE_2;
        maxDeviation = 2;
    } else {
        hitChance = HIT_CHANCE_3;
        maxDeviation = 3;
    }

    int chance = rand() % 100;
    int result = (chance < hitChance) ? target : target + (rand() % (2 * maxDeviation + 1) - maxDeviation);

    int wind = rand() % 3 - 1;
    result += wind;

    if (result < 0) result = 0;
    if (result >= FIELD_SIZE) result = FIELD_SIZE - 1;

    return result;
}

void playAsyq() {
    srand(time(NULL));

    char field[FIELD_SIZE] = {'A', '_', 'A', '_', 'A', 'S', '_', 'A', '_', '_'};
    int playerTurn = 1;
    int playerScore = 0, botScore = 0;
    extern int gameFinished;

    printField(field);

    while (1) {
        int target, power;
        if (playerTurn) {
            printf(" \n");
            printf("choose where to throw asyq (0-9): ");
            scanf("%d", &target);
            printf(" \n");
            printf("how powerful is your throw going to be? (1 - weak, 2 - average, 3 - strong): ");
            scanf("%d", &power);
            printf(" \n");
        } else {
            target = rand() % FIELD_SIZE;
            power = rand() % 3 + 1;
            printf(" \n");
            printf("your opponent chose to throw on position %d with power %d\n", target, power);
            printf(" \n");
        }

        int result = throwAsyq(target, power);

        if (field[result] == 'S') {
            if (playerTurn) {
                printf("congatulations! you hit shik(S)!\n");
                printf(" \n");
                playerScore += 50;
            } else {
                printf("your opponent hit shik(S)!\n");
                printf(" \n");
                botScore += 50;
            }
            break;
        } else if (field[result] == 'A') {
            printf("hit an asyq on the position %d\n", result);
            printf(" \n");
            field[result] = '_';
            if (playerTurn) playerScore += 10;
            else botScore += 10;
        } else {
            printf("miss :(\n");
            printf(" \n");
        }
        
        printf("score: you - %d,  opponent - %d\n", playerScore, botScore);

        playerTurn = !playerTurn;
        printField(field);
    }

    printf("game over! final score: you - %d, opponent - %d\n", playerScore, botScore);
    gameFinished = 1;
}