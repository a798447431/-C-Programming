/*************************************************************************
	> File Name: EP02-1.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月19日 星期日 18时15分08秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 44
#define MAX_M  4000000
int fib[MAX_N + 5];

int main() {
    fib[0] = 2;
    fib[1] = 1; fib[2] = 2;
    for (fib[0] = 2; fib[fib[0]] <= MAX_M; fib[0]++) {
        fib[fib[0] + 1] = fib[fib[0]] + fib[fib[0] - 1];
    }
    long long sum = 0;
    for (int i = 1; i <= fib[0]; i++) {
        if (fib[i] % 2) continue;
        sum += fib[i];
    }
    printf("%d\n", sum);
    return 0;
}
