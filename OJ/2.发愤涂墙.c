/*************************************************************************
	> File Name: 2.发愤涂墙.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月24日 星期四 22时01分08秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 45

long long arr[MAX_N + 5];

int main() {
    int n;
    scanf("%d", &n);
    arr[0] = 0;
    arr[1] = 2;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("%lld\n", arr[n]);
    return 0;
}
