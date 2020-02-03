/*************************************************************************
	> File Name: array.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月04日 星期六 16时49分32秒
 ************************************************************************/

#include<stdio.h>

int func(int *a) { //a 形参
    *a = 123;
    *(a + 0) = 123;
    a[0] = 123;
    return 0;
}

*(arr + i) 
arr[i]

int main() {
    int arr[100];
    printf("&arr[0] = %p arr = %p\n", &arr[0], arr);
    printf("arr + 1 = %p, arr + 2 = %p\n", arr + 1, arr + 2);
    char *p = (char *)arr;
    printf("p + 1 = %p, p + 2 = %p\n", p + 1, p + 2);
    int n = 0;
    func(&n);
    printf("%d\n", n);
    return 0;
}
