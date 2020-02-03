/*************************************************************************
	> File Name: oj98.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月05日 星期五 22时48分53秒
 ************************************************************************/

#include <stdio.h>
#define PI 3.14

int main() {
    double r, h;
    scanf("%lf%lf", &r, &h);
    printf("%.2lf\n", r * r * PI);
    printf("%.2lf\n", r * r * PI * h);
    return 0;
}
