/*************************************************************************
	> File Name: runnian.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月02日 星期二 17时26分31秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        printf("L\n");
    } else {
        printf("N\n");
    }
    return 0;
}
