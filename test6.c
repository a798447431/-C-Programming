/*************************************************************************
	> File Name: test6.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月28日 星期六 14时15分40秒
 ************************************************************************/

#include <stdio.h>

int f1(int x) {
    return x + 1;    
}

int f2(int *x) {
    return (*x) = (*x) + 1;
}

void swap2(int *p, int *q) {
    int *temp;
    *temp = *p;
    *p = *q;
    *q = *temp;
}

void swap3(int *p, int *q) {
    int *temp;
    temp = p;
    p = q;
    q = temp;
}


int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    //swap2(&x, &y);
    swap3(&x, &y);
    printf("%d %d\n", x, y);
    printf("%d\n", f2(&x));
    return 0;
}
