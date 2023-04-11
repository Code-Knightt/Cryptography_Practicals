#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char letters[] = "abcdefghiklmnopqrstuvwxyz";
char included[25];
int myindex = 0;

int check(char letter){
    int i;
    for(i=0;i<25;i++){
        if(included[i] == '\0'){
            break;
        }
        if(included[i] == letter){
            return 1;
        }
    }
    return -1;
}

char** genMatrix(char* key){
    int keylen = strlen(key);
    int i,j,k=0;
    char** matrix = (char**)malloc(5*sizeof(char*));
    for(i=0;i<5;i++){
        matrix[i] = (char*)malloc(5*sizeof(char));
    }
    
    for(i=0;i<keylen;i++){
        if(check(key[i]) == -1){
            matrix[k%5][k/5] = key[i];
            included[myindex++] = key[i];
            k++;
        }
    }

    for(i=0;i<25;i++){
        if(check(letters[i]) == -1){
            matrix[k%5][k/5] = letters[i];
            included[myindex++] = letters[i];
            k++;
        }
    }
    
    return matrix;
}

char* genPairs(char* message){
    int len = strlen(message);
    int i,k=0;
    char* modified = (char*)malloc(2*len*sizeof(char));

    int insert = 0;

    for(i=0;i<len;i++){
        int isEven = (i%2);
        if(message[i] == ' '){
            continue;
        }

        if(message[i] == message[i+1]){
            if(isEven==0){
                insert = 1;
            }
        }
        modified[k++] = message[i];

        if(insert==1){
            modified[k++] = 'x';
            insert=0;
        }

        if(i==len-1 && isEven==0){
            modified[k++]='x';
        }
    }

    return modified;
}

int* find(char** matrix, char letter){
    int* coords = (int*)malloc(2*sizeof(int));
    int i,j;

    for(j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(matrix[i][j] == letter){
                coords[0] = i;
                coords[1] = j;
                break;
            }
        }
    }
    return coords;
}

char* crypt(char** matrix, char* message, int direction){
    int len = strlen(message);
    char* cipher = (char*)malloc(len * sizeof(char));

    int i,k=0;
    for(i=0;i<len;i++){

        if(i%2 != 0){
            continue;
        }

        int* letter_1 = find(matrix, message[i]);
        int* letter_2 = find(matrix, message[i+1]);
        int y1=letter_1[0],x1=letter_1[1];
        int y2=letter_2[0],x2=letter_2[1];

        if(y1 == y2){

            if(direction==-1){
                cipher[k++] = matrix[y1][(x1+4)%5];
                cipher[k++] = matrix[y1][(x2+4)%5];
                continue;
            }

            cipher[k++] = matrix[y1][(x1+1)%5];
            cipher[k++] = matrix[y1][(x2+1)%5];
            continue;
        }

        if(x1 == x2){

            if(direction==-1){
                cipher[k++] = matrix[(y1+4)%5][x1];
                cipher[k++] = matrix[(y2+4)%5][x1];
                continue;
            }

            cipher[k++] = matrix[(y1+1)%5][x1];
            cipher[k++] = matrix[(y2+1)%5][x1];
            continue;
        }

        cipher[k++]=matrix[y2][x1];
        cipher[k++]=matrix[y1][x2];
        free(letter_1);
        free(letter_2);
    }
    return cipher;
}   

void main(){
    char message[] = "tall trees";
    char key[] = "occurrence";
    char** matrix = genMatrix(&key);
    char* modified = genPairs(&message);
    char* encryption = crypt(matrix, modified, 1);
    char* decryption = crypt(matrix, encryption, -1);

    int i,j;
    printf("Playfair Matrix:\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("|%c ",matrix[j][i]);
        }
        printf("\n");
    }
    printf("\nMessage:\t%s\n", modified);
    printf("Encryption:\t%s\n", encryption);
    printf("Decryption:\t%s\n", decryption);

    free(encryption);
    free(decryption);
    free(modified);
    free(matrix);
}