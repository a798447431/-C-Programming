/*************************************************************************
	> File Name: EP47.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月09日 星期六 08时56分32秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

#define MAX_N 1000000

int32_t a[MAX_N + 5] = {0};
int32_t prime[MAX_N] = {0};

int32_t main() {
    for (int32_t i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {prime[++prime[0]] = i; a[i] = 1;} 
        for (int32_t j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                a[i * prime[j]] = a[i];
                break;
            }else {
                a[i * prime[j]] = a[i] + 1;
            }
        }
    }
    for (int32_t i = 6; i <= MAX_N - 3; i++) {
        if (a[i] != 4) continue;
        if (a[i] != a[i + 1]) continue;
        if (a[i + 1] != a[i + 2]) continue;
        if (a[i + 2] != a[i + 3]) continue;
        printf("%d\n", i);
        break;
    }
    return 0;
}
