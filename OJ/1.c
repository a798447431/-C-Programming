/*************************************************************************
	> File Name: 1.cpp
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月19日 星期五 22时29分13秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int m = 2 * n;
    for (int i = 0; i < n; i++) {
        for (int j = m; j > 0; j--) {
            printf("A");
        }
        printf("\n");
        m -= 2;
    }
    return 0;
}
