/*************************************************************************
	> File Name: 折半查找.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月04日 星期六 15时18分32秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <math.h>

int binary_search(int *arr, int n, int x) {
    int head = 0; tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int arr[100];

double my_sqrt(double y) {
    #define EXP 1e-7
    double head = 0, tail = y, mid;
    while (tail - head > EXP) {
        mid = (head + tail) / 2.0;
        if (mid * mid < y) head = mid;
        else tail = mid;
    }
    return head;
}

double f(double x, double y) {
    return x * x - y;
}

double f_prime(double x) {
    return 2 * x;
}

double newton_sqrt(double y) {
    #define EXP 1e-7
    double x = 0;
    while (fabs(f(x, y)) > EXP) {
        x = x - (f(x, y) / f_prime(x));
    }
    return x;
}

#define TEST_FUNC(func, TIMES) {
    int b = clock();
    for (int i = 0; i < TIMES; i++) {
        double temp = 
    }
    int e = clock();
    printf("Test %s : %lf s\n", #func, 1.0 * )
}

int main() {
    for (int i = 0; i < 1000000; i++) {
        int b, e;
        double a = my_sqrt(i);
        double b = sqrt(i);
    }    
    printf("%lf\n", my_sqrt(2.0));
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    while (!scanf("%d", &a)) {
        printf("binary_search result = %d\n", binary_search(arr, n, a));
    }
    
    return 0;
}
