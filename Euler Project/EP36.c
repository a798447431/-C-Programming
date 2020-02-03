/*************************************************************************
	> File Name: EP36.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月25日 星期一 11时25分54秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000
int reverseNum(int x, int base){
    if(base <= 1){
        return 0;
    }
    int n = 0;
    while(x){
        n = n * base + x % base;
        x /= base;
    }
    return n;
}
    
int main(){
    int sum = 0, base2, base10;
    for(int i = 1; i < MAX_N; i++){
        base2 = reverseNum(i, 2);
        base10 = reverseNum(i, 10);
        if(base2 == base10 && base10 == i){
            printf("%d\n", i);
             sum += i;
        }
    }
    printf("%d\n", sum);

    return 0;
}
