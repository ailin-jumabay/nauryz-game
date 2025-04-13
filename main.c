#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "qyzquu.h"    
#include "asyqatu.h"   
#include "otbasym.h"   

int gameFinished = 0;

void displayMenu() { //display menu function
    printf("\n");
    printf("1. play Qyz Quu\n");
    printf("2. play Asyq Atu\n");
    printf("3. play 'Otbasym' hangman\n");
    printf("4. exit\n");
    printf("\nplease enter your choice: ");
}

int main() {
    int choice;
    int keepPlaying = 1;  
    char input[100];  
    char celebrate;

    while (1) {
        printf("\ndo you want to celebrate nauryz? (Y/N): ");
        
        if (fgets(input, sizeof(input), stdin)) {
            size_t len = strlen(input);

            // it removes the newline character at the end of the input, if present
            // fgets() includes the '\n' when the user presses enter
            // and replaces '\n' with '\0' to clean up the input string
            if (input[len - 1] == '\n') { 
                input[len - 1] = '\0';
                len--;
            }

            if (len != 1) {
                printf("invalid input! please enter only one letter (Y or N).\n");
                continue; //if length is more than 1 symbol it throws invalid value 
                //and continues code so it asks again
            }

            celebrate = tolower(input[0]); //lower or upper case blindness

            if (celebrate == 'n') {
                printf("\nokay :( maybe next year... sau bol!\n");
                return 0;  
            } else if (celebrate == 'y') {
                printf("\nlet's celebrate nauryz together! what do you want to play?\n");
                break;  
            } else {
                printf("invalid input! please enter Y or N.\n");
            }
        } else {
            printf("input error!\n");
            break;
        }
    }
    while (keepPlaying) {
        
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playQyzQuu();
                break;
            case 2:
                printf("\n");
                printf("salem! loading Asyq Atu...\n");
                printf("\nrules: you have a field with 10 asyqs on certain positions. \n1 of the asyqs is a speciall one, shyq, it's bigger than the rest\nif you hit shyq, you will imidiatelly win! good luck!\n \n*asyq - ankle bone of the back legs of the sheep\n \n*shyq - 'exit' in qazaq\n");
                playAsyq();
                break;
            case 3:
                printf("\nsalem! loading 'Otbasym' hangman...\n");
                printf("\nrules: you have a classic hangman gameplay, \nbut the words you need to guess are terms and names used to describe \na certain member of qazaq family! good luck!\n \n*every word will be showen with definition by the end of the game\n");
                playHangman();
                break;
            case 4:
                printf("\nraqmet for playing! sau bol!\n");
                keepPlaying = 0;
                gameFinished = 0;
                break;
            default:
                printf("\ninvalid choice\n");
        } //choice of game

        if (gameFinished) {
            printf("\ndo you want to play something again? (1 for yes, 0 for no): ");
            int playAgain;
            scanf("%d", &playAgain); //shows menu again if user wants to play again
            if (playAgain == 0) {
                keepPlaying = 0;
                printf("\nraqmet for playing! sau bol!\n"); //if no code ends

} 

    }
}
   
    
    return 0;
}
