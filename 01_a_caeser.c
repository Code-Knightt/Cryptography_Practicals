#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int encrypt(){
    int shift;
    char string[MAX_SIZE];

    printf("\nEnter string: ");
    gets(&string);
    printf("Enter shift: ");
    scanf("%d", &shift);

    int length = strlen(string);
    char encryption[MAX_SIZE];

    int i;
    for(i=0;i<length;i++){
        char letter = tolower(string[i]);
        int lettercode = (int) letter;

        if(lettercode >= 97 && lettercode <= 122){
            int newcode = lettercode + (shift%26);
            if(newcode > 122){
                newcode -= 26;
            } else if (newcode < 97){
                newcode += 26;
            }

            encryption[i] = (char) (newcode);
        } else {
            encryption[i] = letter;
        }
    }
    encryption[length] = '\0';
    printf("Encryption: %s", encryption);
    return 0;
}

int decrypt(){
    char ciphertext[MAX_SIZE];
    char message[MAX_SIZE];

    int shift;
    fflush(stdin);
    printf("\n\nEnter ciphertext: ");
    gets(&ciphertext);
    printf("Enter shift: ");
    scanf("%d", &shift);

    int length = strlen(ciphertext);

    int i;
    for(i=0; i<length; i++){
        char letter = ciphertext[i];
        int lettercode = (int) letter;

        if(lettercode >=97 && lettercode <=122){
            int newcode = lettercode - (shift%26);
            if(newcode < 97){
                newcode += 26;
            }
            message[i] = (char) newcode;
        } else {
            message[i] = letter;
        }
    }
    message[length] = '\0';

    printf("Decryption: %s\n", message);
    return 0;
}

int main(){
    encrypt();
    decrypt();
    return 0;
}