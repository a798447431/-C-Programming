/*************************************************************************
	> File Name: oj89.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年06月26日 星期三 23时16分52秒
 ************************************************************************/

#include <stdio.h>

void quweishu(int n) {
    if (n < 10) {
        printf("%d\n", n);
    } else {
        quweishu(n / 10);
        printf("%d\n", n % 10);
    } 
    return ;
}

int main() {
    int a;
    scanf("%d", &a);
    quweishu(a);
    return 0;
}
