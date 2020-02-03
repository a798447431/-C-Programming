/*************************************************************************
	> File Name: 6.核电站.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月25日 星期五 18时25分46秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 100000
long long arr[MAX_N + 5];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i < m) arr[i] = 2 * arr[i - 1];
        if (i == m) arr[i] = arr[i - 1] * 2 - 1;
        if (i > m) arr[i] = arr[i - 1] * 2 - arr[i - m - 1];
    }
    printf("%lld\n", arr[n]);
    return 0;
}
