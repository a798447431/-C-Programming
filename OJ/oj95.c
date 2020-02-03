/*************************************************************************
	> File Name: oj95.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月05日 星期五 22时38分10秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, temp = 0;
    scanf("%d", &n);
    while (n) {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    printf("%d\n", temp);
    return 0;
}
