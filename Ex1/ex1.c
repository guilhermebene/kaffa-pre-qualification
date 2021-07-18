#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define CNPJ_LENGTH 14

int main(){

    // Fixed orders for confirmation
    const int fixed_sequence1[] = {5,4,3,2,9,8,7,6,5,4,3,2};
    const int fixed_sequence2[] = {6,5,4,3,2,9,8,7,6,5,4,3,2};
    const char fixed_punctuations[] = {'.','.','/','-'};

    int *cnpj = calloc(CNPJ_LENGTH,sizeof(int));
    char punctuations[4];
    char aux;

    int number_counter = 0;
    int punct_counter = 0;

    bool punct_invalid = false;
    
    // Reading data from keyboard
    // -------------------------------------------------------------------------
    printf("Insert a CNPJ: ");
    while(true){

        aux = getchar();

        if(aux == '\n')
            // If the user types '\n' too early
            if(number_counter < CNPJ_LENGTH - 1){
                printf("Invalid CNPJ (too small)");
                return -1;
            }
            // If the CNPJ is completely typed
            else
                break;

        if(!isdigit(aux)){
            if(aux != fixed_punctuations[punct_counter])
                punct_invalid = true;
            else
                punct_counter++;
        }

        else{
            cnpj[number_counter] = aux - '0'; // Converting digit to integer
            number_counter++;
        }
    }

    // printf("Numbers received: ");
    // for(int j=0; j<CNPJ_LENGTH; j++)
        // printf("%d", cnpj[j]);
    // printf("\n");

    if(punct_invalid){
        printf("Invalid CNPJ punctuation\n");
        return -1;
    }

    // Verifying data
    // -------------------------------------------------------------------------
    int result1 = 0;
    int result2 = 0;

    int remainder1 = 0;
    int remainder2 = 0;

    int confirmation1 = 0;
    int confirmation2 = 0;

    for(int j = 0; j < CNPJ_LENGTH-2; j++)
        result1 += cnpj[j] * fixed_sequence1[j];
        
    for(int j = 0; j < CNPJ_LENGTH-1; j++)
        result2 += cnpj[j] * fixed_sequence2[j];

    // Verifying first confirmation digit

    remainder1 = result1 % 11;

    if(remainder1 < 2)
        confirmation1 = 0;
    else
        confirmation1 = 11 - remainder1;

    // Verifying second confirmation digit

    remainder2 = result2 % 11;

    if(remainder2 < 2)
        confirmation2 = 0;
    else
        confirmation2 = 11 - remainder2;

    if(confirmation1 != cnpj[CNPJ_LENGTH - 2] || confirmation2 != cnpj[CNPJ_LENGTH - 1]){
        printf("Invalid CNPJ\n");
        return -1;
    }

    else{
        printf("Valid CNPJ\n");
        return 0;
    }

}