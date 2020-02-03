/*************************************************************************
	> File Name: EP32.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月04日 星期一 15时43分59秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 10000


int digit(int x) {
    return floor(log10(x)) + 1;
}

int get_digit(int a, int *num) {
    while (a) {
        if (a % 10 == 0) return 0;
        if (num[a % 10]) return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    return 1;   
}

int is_digit(int a, int b, int c) {
    int num[10] = {0};
    if (!get_digit(a, num)) return 0;
    if (!get_digit(b, num)) return 0;
    if (!get_digit(c, num)) return 0;
    return 1;
}

int vaild[max_n] = {0};

int main() {
    int ans = 0;
    for (int a = 2; digit(a) + digit(a) + digit(a * a) <= 9; a++) {
        for (int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {
            if (digit(a) + digit(b) + digit(a * b) < 9) continue;
            if (is_digit(a, b, a * b)) {
                ans += a * b * (1 - vaild[a * b]);
                vaild[a * b] = 1;
                printf("%d * %d = %d\n", a, b, a * b);
            }
        }
    }


    printf("%d\n", ans);
    return 0;
}
