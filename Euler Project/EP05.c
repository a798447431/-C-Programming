/*************************************************************************
	> File Name: EP05.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月19日 星期二 19时39分07秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a % b);
    // return (b ? gcd(b, a % b) : a);
}

int main(){
   /* for(int i = 1; 1; i++){
        if(i%1==0 && i%2==0 && i%3==0 && i%4==0 && i%5==0 && i%6==0
           && i%7==0 && i%8==0 && i%9==0 && i%10==0 && i%11==0 && i%12==0
           && i%13==0 && i%14==0 && i%15==0 && i%16==0 && i%17==0 && i%18==0
           && i%19==0 && i%20==0
          ){
              printf("%d\n", i);
              break;
          }
    }*/

  /*  long number = 20;
    while(!(number % 20 == 0 && number % 19 == 0 && number % 18 == 0 &&
            number % 17 == 0 && number % 16 == 0 && number % 15 == 0 &&
            number % 14 == 0 && number % 13 == 0 && number % 12 == 0 &&
            number % 11 == 0 )){
                number += 20;
            } 
    
    printf("%ld\n", number);*/
    
    int ans = 1;
    for(int i =1; i <= 20; ++i){
        ans *= i/gcd(i, ans);
    }

    printf("%d\n", ans);


    return 0;
}

