/*************************************************************************
	> File Name: oj86.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年06月26日 星期三 22时12分00秒
 ************************************************************************/

#include <stdio.h>

int qmul(int a, int b) {
    int ans = 0;
    while (b) {
        if (b & 1) ans += a;
        b >>= 1;
        a <<= 1;
    }
    return ans;
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int tmp = qmul(a, b);
    printf("%d\n", qmul(tmp, c));
    return 0;
}
