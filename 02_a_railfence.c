#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encrypt(char* message, int key){ 
    int i,j=0,k=0;
    int direction = 1;
    int cols = strlen(message);
    int rows = key;
    char** table = (char**)malloc(cols * sizeof(char*));
    char* cipher = (char*)malloc(cols * sizeof(char));

    for(i=0; i<cols; i++){
        table[i] = (char*)malloc(rows * sizeof(char));
    }

    for(i=0;i<cols;i++){
        table[i][j] = message[i];
        if(j==rows-1){
            direction = -1;
        }
        if(j==0){
            direction = 1;
        }
        j += direction;
    }

    for(j=0;j<rows;j++){
        for(i=0;i<cols;i++){
            if(table[i][j] != '\0'){
                cipher[k++] = table[i][j];
            }
        }
    }
    free(table);
    return cipher;
}

char* decrypt(char* message, int key){ 
    int i,j=0,k=0,l=0;
    int direction = 1;
    int cols = strlen(message);
    int rows = key;
    char** table = (char**)malloc(cols * sizeof(char*));
    char* plain = (char*)malloc(cols * sizeof(char));

    for(i=0; i<cols; i++){
        table[i] = (char*)malloc(rows * sizeof(char));
    }

    int curr = 0;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(k==curr){
                table[j][k] = message[l++];
            }
            if(k==rows-1){
                direction = -1;
            }
            if(k==0){
                direction = 1;
            }
            k += direction;
        }
        curr++;
    }

    k = 0;
    for(i=0;i<cols;i++){
        for(j=0;j<rows;j++){
            if(table[i][j] != '\0'){
                plain[k++] = table[i][j];
            }
        }
    }
    free(table);
    return plain;
}

void main(){
    char message[] = "meetme";
    int key = 2;
    char *encryption = encrypt(&message, key);
    char * decryption = decrypt(encryption, key);

    printf("Message:\t%s\n", message);
    printf("Encryption:\t%s\n",encryption);
    printf("Decryption:\t%s\n",decryption);
    free(encryption);
    free(decryption);
}