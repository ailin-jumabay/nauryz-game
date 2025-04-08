#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 6 

char* getRandomWord() {
    FILE *file = fopen("otbasym.txt", "r");
    if (file == NULL) {
        printf("no file found\n");
        exit(1);
    }

    int wordCount = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        wordCount++;
    }
    rewind(file);

    srand(time(NULL));
    int randomIndex = rand() % wordCount;

    for (int i = 0; i <= randomIndex; i++) {
        fgets(line, sizeof(line), file);
    }
    fclose(file);

    line[strcspn(line, "\n")] = 0;

    char *word = malloc(strlen(line) + 1);
    strcpy(word, line);

    return word;
}

char* getDefinition(char *word) {
    FILE *file = fopen("definitions.txt", "r");
    if (file == NULL) {
        printf("no file found\n");
        exit(1);
    }

    char line[200];
    char *definition = malloc(200);
    while (fgets(line, sizeof(line), file)) {
        
        char *wordInFile = strtok(line, "-");  
        if (wordInFile && strcmp(wordInFile, word) == 0) {
            strcpy(definition, strtok(NULL, "\n"));  
            fclose(file);
            return definition;
        }
    }
    fclose(file);
    return "no definitions found"; 
}

void displayGame(char *word, char *guessed, int triesLeft) {
    printf("\nguessed letters: %s\n", guessed);
    printf("attempts left: %d\n", triesLeft);
    
    for (int i = 0; i < strlen(word); i++) {
        if (strchr(guessed, word[i])) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void playHangman() {
    char *word = getRandomWord();
    int wordLength = strlen(word);
    
    char guessed[100] = {0};
    int triesLeft = MAX_TRIES;
    int guessedCorrectly = 0;
    extern int gameFinished;


    while (triesLeft > 0) {
        displayGame(word, guessed, triesLeft);

        char guess;
        printf("enter your letter: ");
        scanf(" %c", &guess);

        if (strchr(guessed, guess)) {
            printf("u already guessed this one\n");
            continue;
        }

        strncat(guessed, &guess, 1);

        if (strchr(word, guess)) {
            printf("yes! '%c' letter is there\n", guess);
        } else {
            printf("no! '%c' letter is not there\n", guess);
            triesLeft--;
        }

        guessedCorrectly = 0;
        for (int i = 0; i < wordLength; i++) {
            if (strchr(guessed, word[i])) {
                guessedCorrectly++;
            }
        }

        if (guessedCorrectly == wordLength) {
            break;
        }
    }

    if (guessedCorrectly == wordLength) {
        printf("\ncongratulations! you gueesed the word: %s\n", word);
        gameFinished = 1;
        char *definition = getDefinition(word);
        printf("definition: %s\n", definition);
        free(definition);
    } else {
        printf("\ngame over! word was: %s\n", word);
        gameFinished = 1;
    }

    free(word);
}