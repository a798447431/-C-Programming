/*************************************************************************
	> File Name: test4.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月21日 星期四 18时37分18秒
 ************************************************************************/
#include <stdio.h>

void swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > c) {
		swap(&a, &c);
	}
	if (b > c) {
		swap(&b, &c);
	}
	if (a + b <= c) {
		puts("It's not a triangle");
	} else if (a * a + b * b < c * c) {
		puts("It's an obtuse triangle");
	} else if (a * a + b * b > c * c) {
		puts("It's an acute triangle");
	} else {
		puts("It's a right triangle");
	}
	return 0;
}
