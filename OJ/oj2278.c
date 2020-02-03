/*************************************************************************
	> File Name: oj2278.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月16日 星期五 14时45分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int l;
    scanf("%d", &l);
    char *str = (char *)malloc(sizeof(char) * l);
    
    for (int i = 0; i < l; i++) {
        scanf("%c", &str[i]);
    }

    return 0;
}

