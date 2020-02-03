/*************************************************************************
	> File Name: test7.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月28日 星期六 14时49分26秒
 ************************************************************************/

#include<stdio.h>

char *str1A() {
    char str[] = "hello world";
    return str;
}

/*
char *str2A() {
    char *str = "hello world";
    return str;
}
*/

int main() {
    printf("%s\n", str1A());
//    printf("%s\n", str2A());
    return 0;
}
