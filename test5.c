/*************************************************************************
	> File Name: test5.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月26日 星期四 18时42分28秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int b = 500, c = 700;
    //const int *a = &b;
    //*a = 12;
    
    //int const *a = b;
    int *const a = &b;
    *a = 12;
    printf("%d\n", *a);
    a = &c;
    //const int* const a = &b;
    
    return 0;
}

