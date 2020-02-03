/*************************************************************************
	> File Name: oj329.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月24日 星期六 15时23分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int c[MAX_N + 5];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}

int query(int x) {
    int sum = 0;
    while (x) sum += c[x], x -= lowbit(x);
    return sum;
}

int main() {
    int n, m, pre = 0, now;
    char str[10];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &now);
        add(i, now - pre, n);
        pre = now;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        switch (str[0]) {
            case 'C': {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                add(a, c, n);
                add(b + 1, -c, n);
            } break;
            case 'Q': {
                int x;
                scanf("%d", &x);
                printf("%d\n", query(x));
            }
        }
    }
    return 0;
}

