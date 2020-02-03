/*************************************************************************
	> File Name: EP02.3.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月18日 星期一 14时06分46秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 4000000

int main(){
   
    int fib[3], n = 2, ans = 0;
    
    fib[0] = fib[1] = 1;
   
    while(fib[(n) % 3] <= MAX_N) {
       
        if((fib[(n) % 3] & 1) == 0){
           
            ans += fib[(n - 1) % 3];
       
        }
       
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
       
        n += 1;
    }

    printf("%d\n", ans);

    return 0;
}
