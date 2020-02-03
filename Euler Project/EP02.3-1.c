/*************************************************************************
	> File Name: EP02.3-1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月18日 星期一 14时32分36秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 4000000

int main(){
   
   /* int fib[4] = {1, 0, 1}, n = 3, ans = 0;
   
    while(fib[(n - 1) % 4] <= MAX_N){
       

        fib[n % 4] = fib[(n - 2) % 4] + fib[(n - 3) % 4];
       
        printf("%d\n", fib[(n - 1) % 4]);

        n += 1;

        
    }
   
    printf("%d\n", ans);
   
    return 0; */


    int fib[2] = {1, 1}, n = 2, ans = 0;
   
    while(fib[(n - 1) % 2] <= MAX_N) {
        
        if(fib[(n - 1) % 2] % 2 == 0) ans += fib[(n - 1) % 2];

        fib[n % 2] += fib[(n - 1) % 2];

        n += 1;
    
    }
    
    printf("%d\n", ans);
    
    return 0;

}
