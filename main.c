#include <stdio.h>
#include <stdlib.h>
#include "qyzquu.h"    
#include "asyqatu.h"   
#include "otbasym.h"   

int gameFinished = 0;

void displayMenu() {
    printf("\n");
    printf("let's celebrate nauryz together! what do you want to play?\n");
    printf("\n");
    printf("1. play Qyz Quu\n");
    printf("2. play Asyq Atu\n");
    printf("3. play 'Otbasym' hangman\n");
    printf("4. exit\n");
    printf("\n");
    printf("please enter your choice: ");
    printf("\n");
}


int main() {
    int choice;
    int keepPlaying = 1;  

    char celebrate;
    printf("do you want to celebrate nauryz? (Y/N): ");
    scanf(" %c", &celebrate);  // Добавлен пробел перед %c для корректной работы с буфером

    if (celebrate == 'N' || celebrate == 'n') {
        printf("\n");
        printf("okay :( maybe next year... sau bol!\n");
        return 0;  
    }

    while (keepPlaying) {
        
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playQyzQuu();
                break;
            case 2:
                printf("salem! loading Asyq Atu...\n");
                printf("rules: you need to \n");
                playAsyq();
                break;
            case 3:
                printf("salem! loading 'Otbasym' hangman...\n");
                printf("rules: guess the term for qazaq family member!\n");
                playHangman();
                break;
            case 4:
                printf("raqmet for playing! sau bol!\n");
                keepPlaying = 0;  
                break;
            default:
                printf("invalid choice\n");
        }

        if (gameFinished) {
            printf("\ndo you want to play again? (1 for yes, 0 for no): ");
            int playAgain;
            scanf("%d", &playAgain);
            if (playAgain == 0) {
                keepPlaying = 0;
                printf("raqmet for playing! sau bol!\n");
            }
        }
    }

    return 0;
}
