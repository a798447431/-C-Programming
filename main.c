/*************************************************************************
	> File Name: main.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月16日 星期四 21时01分06秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int num = 0x64636261;
    char *p = (char *)(&num);
    printf("%s\n", p);
    return 0;
}
