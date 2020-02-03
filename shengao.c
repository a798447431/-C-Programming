/*************************************************************************
	> File Name: shengao.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月01日 星期一 17时01分33秒
 ************************************************************************/

#include <stdio.h>

int main() {
    double m, n;
    int p;
    double son, girl;
    scanf("%lf%lf%d", &m, &n, &p);
    if (p) {
        son = (m + n) * 1.087 / 2.0;
        printf("%.2lf\n", son);
    } else {
        girl = (m * 0.973 + n) / 2.0;
        printf("%.2lf\n", girl);
    }
    return 0;
}
