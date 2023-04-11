#include <stdio.h>

int gcd(int a, int b)
{
    if (a > b){
        if (a % b == 0){
            return b;
        }
        if (b == 0){
            return a;
        }
        else{
            return gcd(a % b, b);
        }
    }

    if (a < b){
        if (b % a == 0){
            return a;
        }
        else if (a == 0){
            return b;
        }
        else{
            return gcd(b % a, a);
        }
    }
}
void main(){
    int a, b;
    printf("Enter the number 1:");
    scanf("%d", &a);
    printf("Enter the number 2:");
    scanf("%d", &b);
    printf("GCD of a&b=%d\n", gcd(a, b));

}