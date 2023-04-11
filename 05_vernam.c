#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char letters[] = "abcdefghijklmnopqrstuvwxyz";

int getIndex(char letter){
    int i;
    for(i=0; i<26;i++){
        if(tolower(letter) == letters[i]){
            return i;
        }
    }
    return -1;
}

char* matchKey(char *key, int length){
    int keylen = strlen(key);
    int i;
    int j = keylen;

    char* newKey = (char*)malloc(length* sizeof(char));
    for(i=0;i<keylen;i++){
        newKey[i] = key[i];
    }

    while(j < length){
        newKey[j] = key[j%keylen];
        j++;
    }
    return newKey;
}

char* crypt(char* message, char* key, int length){
    int i;
    char* crypted = (char*) malloc(length * sizeof(char));

    for(i=0;i<length;i++){
        int index_1 = getIndex(message[i]);
        int index_2 = getIndex(key[i]);
        int answerIndex = index_1 ^ index_2;
        
        crypted[i] = letters[answerIndex % 26];
    }
       
    return crypted;
}

void main(){
    char message[] = "Wearediscoveredsaveyourself";
    char key[] = "deceptive";
    int msglen = strlen(message);
    char *newkey = matchKey(&key, msglen);
    char *encrypted = crypt(&message, newkey, msglen);
    char *decrypted = crypt(encrypted, newkey, msglen);

    puts(encrypted);
    puts(decrypted);
    
    free(newkey);
    free(encrypted);
    free(decrypted);
}