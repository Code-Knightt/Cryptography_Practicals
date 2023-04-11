#include <stdio.h>
#include <string.h>
#include <math.h>

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

int getIndex(char letter){
	int i=0;
	letter = tolower(letter);
	for(i = 0; i<26;i++){
		if(alphabet[i] == letter){
			return i;
		}
	}
	return -1;
}

int** createKeyMatrix(int height, char *key){
	int **matrix = (int**)malloc(height * sizeof(int*));
	int i,j,k,l = 0;
	for(k=0;k<height;k++){
		matrix[k] = (int*)malloc(height * sizeof(int));
	}

	for(i=0;i<height;i++){
		for(j=0;j<height;j++){
			matrix[i][j] = getIndex(key[l++]);
			// printf("%d ",matrix[i][j]);
		}
		// printf("\n");
	}

	return matrix;
}

int** createMatrix(int height, int length, char *string){
	int rows = height;
	int cols = (length/height);
	int** matrix = (int**)malloc(cols * sizeof(int*));
	int i,j,k,l=0;

	for(k=0;k<cols;k++){
		matrix[k] = (int*)malloc(rows * sizeof(int));
	}

	for(i=0;i<cols;i++){
		for(j=0;j<rows;j++){
			matrix[i][j]=getIndex(string[l++]);
			// printf("%d\n",matrix[i][j]);
		}
		// printf("\n");
	}
	return matrix;
}

char* encrypt(int*** keys, int*** letters, int length, int height){

	int cols = (length/height);
	int rows = height;
	int i,j,k,l;
	char* encrypted = (char*)malloc(length * sizeof(char));

	int** result = (int**)malloc(rows * sizeof(int*));

	for(l=0;l<rows;l++){
		result[l] = (int*)malloc(cols * sizeof(int));
	}

	for(i=0;i<rows;i++){
		for(j=0; j<cols; j++){
			result[i][j]=0;    
			for(k=0;k<cols;k++){ 
				result[i][j] += (*keys)[i][k] * (*letters)[j][k];    
			}
			result[i][j] = result[i][j] % 26;

			// printf("%d ", result[i][j]);
			// printf("%c \n", alphabet[result[i][j]]);
		}
		// printf("\n");
	}
	
	l=0;
	for(j=0;j<cols;j++){
		for(i=0;i<rows;i++){
			encrypted[l++] = alphabet[result[i][j]];
		}
	}

	free(result);
	return encrypted;
}

int modInverse(int A, int M){
	int X;
	for (X = 1; X < M; X++){
        if (((A % M) * (X % M)) % M == 1){
            return X;
		}
	}		
}

void matrixInverse(int*** matrix, int height){
	int **inverse = (int**)malloc(height * sizeof(int*));
	int i,j,k,l = 0;
	for(k=0;k<height;k++){
		inverse[k] = (int*)malloc(height * sizeof(int));
	}
}

int main(){
	char word[] = "exam";
	char key[] = "hill";
	int height = 2;
	int length = strlen(word);
	int i;

	if(strlen(key) != 4 && strlen(key) != 9){
		printf("Key length should be either 4 or 9\n");
		return -1;
	}

	int** keys = createKeyMatrix(height, &key);
	int** letters = createMatrix(height, length, &word);
	char* encrypted = encrypt(&keys, &letters, length, height);

	printf("\nOriginal text: ");
	puts(word);
	printf("Encrypted text: ");
	puts(encrypted);

	free(keys);
	free(letters);
	free(encrypted);
    return 0;
}