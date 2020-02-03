/*************************************************************************
	> File Name: 7.回文拆分.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月25日 星期五 19时33分23秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 100000
long long arr[MAX_N + 5];


int main() {
    int k;
    scanf("%d", &k);
    arr[0] = arr[1] = 0;
    for (int i = 2; i <= k; i++) {
        if (i & 1) {
            arr[i] = arr[i - 1];
        } else {
            arr[i] = arr[i - 1] * 2 + 1;
        }
    }
    printf("%lld\n", arr[k]);
    return 0;
}

