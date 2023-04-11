#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* convertKey(char* key){
    int len=strlen(key);
    int i,k;
    int* temp = (int*)malloc(len * sizeof(int));
    int* numbers = (int*)malloc(len * sizeof(int));

    for(i=0;i<len;i++){
        temp[i] = key[i]-'0';
    }

    for(k=1;k<=len;k++){
        for(i=0;i<len;i++){
            if(temp[i] == k){
                numbers[k-1] = i;
                continue;
            }
        }
    }
    free(temp);
    return numbers;
}

char* encrypt(char* message, char* key){
    int cols = strlen(key);
    int len = strlen(message);
    int rows = len % cols == 0 ? len/cols : (len/cols)+1;
    int i,j,k=0;

    char* cipher = (char*)malloc(len*sizeof(char));
    char** table = (char**)malloc(cols * sizeof(char*));
    for(i=0;i<cols;i++){
        table[i] = (char*)malloc(rows * sizeof(char));
    }

    for(j=0;j<rows;j++){
        for(i=0;i<cols;i++){
            if(k<len){
                table[i][j] = message[k++];
            } else {
                table[i][j] = 'x';
            }
        }
    }

    int* order = convertKey(key);

    k=0;
    for(i=0;i<cols;i++){
        for(j=0;j<rows;j++){
            int c = order[i];
            cipher[k++] = table[c][j];
        }
    }
    free(order);
    return cipher;
}

char* decrypt(char* message, char* key){
    int cols = strlen(key);
    int len = strlen(message);
    int rows = len % cols == 0 ? len/cols : (len/cols)+1;
    int i,j,k=0;

    char* plain = (char*)malloc(len*sizeof(char));
    int* order = convertKey(key);

    char** table = (char**)malloc(cols * sizeof(char*));
    for(i=0;i<cols;i++){
        table[i] = (char*)malloc(rows * sizeof(char));
    }

    for(i=0;i<cols;i++){
        for(j=0;j<rows;j++){
            int c = order[i];
            table[c][j] = message[k++];   
        }
    }

    k=0;
    for(j=0;j<rows;j++){
        for(i=0;i<cols;i++){
            plain[k++] = table[i][j];
        }
    }
    free(order);
    return plain;
}

void main(){
    char message[] = "attackpostponeduntiltwoam";
    char key[] = "4312567";
    char* encryption = encrypt(&message, &key);
    char* decryption = decrypt(encryption, &key);
    
    printf("Message:\t%s\n", message);
    printf("Encryption:\t%s\n",encryption);
    printf("Decryption:\t%s\n",decryption);
    
    free(encryption);
    free(decryption);
}