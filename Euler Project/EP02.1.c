/*************************************************************************
	> File Name: EP02.1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月17日 星期日 18时25分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAX_N 4000000

int fib[55] = {0};
int n = 2;

int main(){
    fib[0] = 1; fib[1] = 2;
    while (fib[n - 1] + fib[n - 2] < MAX_N) {
        fib[n] = fib[n - 1] + fib[n - 2];
        n++;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(fib[i] % 2 == 0){
        ans += fib[i];
    }
  }
    printf("%d\n", ans);

    return 0;
}
