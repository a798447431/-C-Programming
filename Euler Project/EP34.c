/*************************************************************************
	> File Name: EP34.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月25日 星期一 09时41分55秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 2540160

int fac(int temp2){
    int fac_mul = 1;
    for(int i = 1; i <= temp2; i++){
        fac_mul = fac_mul * i;
    }
    return fac_mul;
}

int is_vaild(int x){
    int sum = 0, temp1 = x, temp2 = 0 ;
    while(x) {
        temp2 = x % 10;
        sum += fac(temp2);
        x /= 10; 
    }

    return temp1 == sum;
}

int main(){
    int sum = 0;
    for (int i = 3; i <= MAX_N; i++){
        if(!is_vaild(i)) continue;
        printf("%d\n", i);
        sum += i;
    }
    printf("%d\n", sum);

    return 0;
}
