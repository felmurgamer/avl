#include "util.h"
#include "game.h"
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}
void adding_info(AVL* tree){
    FILE* file = NULL;
    char* string = (char*)malloc(120*sizeof(char));
    GAME* game = NULL;

    // file = fopen("CSV.csv","r");
    file = fopen("CSV-TodosJogos.csv","r");
    if(file == NULL){
        printf("ERROR opening the file!\n");
        exit(1);
    }
    fseek(file,3,SEEK_SET);
    while(fgets(string,120,file) != NULL){
    	game = add_game(string);
        avl_insert(tree,game);
    }
    fclose(file);
    free(string);
    return;
}
