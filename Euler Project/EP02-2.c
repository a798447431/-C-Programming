/*************************************************************************
	> File Name: EP02-2.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月19日 星期日 18时15分08秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 44
#define MAX_M  4000000
int fib[MAX_N + 5];

int main() {
    long long sum = 2;
    int a = 0, b = 1;
    while (a + b < MAX_M) {
        b = a + b;
        a = b - a;
        if (!(b & 1)) {
            sum += b;
        }
    }
    printf("%d\n", sum);
    return 0;
}
