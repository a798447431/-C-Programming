/*************************************************************************
	> File Name: 5.新约瑟夫游戏.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月25日 星期五 19时27分45秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 32767
long long arr[MAX_N + 5][2];

int main() {
    int n;
    scanf("%d", &n);
    arr[1][0] = 1; 
    arr[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i][0] = (arr[i - 1][0] + 1) % i  + 1;
        if (arr[i][0] == i) {
            arr[i][1] = i;
        } else {
            arr[i][1] = arr[arr[i][0]][1];
        }
    }
    printf("%lld\n", arr[n][1] + n);
    return 0;
}
