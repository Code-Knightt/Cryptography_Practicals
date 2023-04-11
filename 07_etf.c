#include<stdio.h>

int gcd(int a,int b){   
    if(a>b){   
        if(a%b==0){
            return b;
        }
        else if(b==0){
            return a;
        }else{
            return gcd(a%b,b);
        }
    }else{
        if(b%a==0){
            return a;
        }
        else if(a==0){
            return b;
        }
        else{
           return gcd(b%a,a);
        }
    }
}

int fun(int n){
    int i,ans=0;
    for(i=1;i<n;i++){
       if(gcd(i,n)==1){
            ans++;
        }       
    }
    return ans; 
}

void main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("phi(%d)=%d",n,fun(n));
}
