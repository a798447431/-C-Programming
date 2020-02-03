/*************************************************************************
	> File Name: EP18.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年06月25日 星期二 18时40分41秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 15
#define max ((a) > (b) ? (a) : (b));

int val[MAX_N + 5][MAX_N + 5];
int mamory[MAX_N + 5][MAX_N + 5];
/*
int dfs(int i, int j, int n) {
    if (i + 1 == n) {
        return val[i][j];
    }
    if (mamory[i][j] != 0) return mamory[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    mamory[i][j] =  (val1 > val2 ? val1 : val2) + val[i][j];
    return mamory[i][j];
}
*/
int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i ; j++) {
            scanf("%d", &val[i][j]);
        }
    }
    for (int i = MAX_N - 2; i >= 0; --i) {
        for (int j = 0; j <= i; j++) {
            val[i][j] += max(val[i + 1][j], val[i + 1][j + 1]);
        }
    }
    printf("%d\n", val[0][0]);
    return 0;
}
