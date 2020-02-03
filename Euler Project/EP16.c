/*************************************************************************
	> File Name: EP16.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月05日 星期二 19时41分37秒
 ************************************************************************/

#include <stdio.h>
#define BASE 100000

int get_digit(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int ans[600] = {0};
    ans[0] = ans[1] = 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 1; j <= ans[0]; j++) ans[j] <<= 10;
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < BASE) continue;
            ans[j + 1] += ans[j] / BASE;
            ans[j] %= BASE;
            ans[0] += (j == ans[0]);
        }
    }

    int sum = 0;
    for (int i = 1; i <= ans[0]; i++) sum += get_digit(ans[i]);
    printf("%d\n", sum);
    return 0;
}
