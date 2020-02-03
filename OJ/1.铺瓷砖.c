/*************************************************************************
	> File Name: 1.铺瓷砖.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月24日 星期四 21时50分02秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000

int arr[MAX_N + 5];
 
int main() {
    int n;
    scanf("%d", &n);
    arr[0] = arr[1] = 1;
    for(int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] * 2;
        arr[i] %= 12345;
    }
    printf("%d\n", arr[n]);
    return 0;
}
