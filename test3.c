/*************************************************************************
	> File Name: test3.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月24日 星期二 20时10分16秒
 ************************************************************************/

#include <stdio.h>

int main() {
    unsigned int a = 0xFFFFFFF7;
    unsigned char c = (unsigned char) a;
    char *b = (char *)&a;
    printf("%08x, %08x\n", c, *b);
    return 0;
}

