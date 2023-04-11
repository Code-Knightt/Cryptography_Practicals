#include <stdio.h>

int extended_euclid(int m, int b){
    int a1=1, a2=0, a3=m;
    int b1=0, b2=1, b3=b;

    while(b3 != 1){
        if(b3==0){
            return -1;
        }

        int q = a3/b3;
        int t1 = a1 - q*b1;
        int t2 = a2 - q*b2;
        int t3 = a3%b3;
        a1=b1;a2=b2;a3=b3;
        b1=t1;b2=t2;b3=t3; 

        if(b3==1){
            if(b2 < 0){
                b2 = b2 % m;
            }
            return b2;
        }
    }
}

void main(){
    int answer = extended_euclid(49,37);
    printf("%d\n",answer);
}