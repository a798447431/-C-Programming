/*************************************************************************
	> File Name: 2.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月19日 星期五 18时53分00秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 500000

int arr1[MAX_N + 5];
int arr2[MAX_N + 5];
int s1[MAX_N + 5], top1 = -1;
int s2[MAX_N + 5], top2 = -1;

void read(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    read(arr1, n);
    read(arr2, n);
    for (int i = 0; i < n; i++) {
        while (top1 != -1 && arr1[s1[top1]] >= arr1[i]) top1--;
        while (top2 != -1 && arr2[s2[top2]] >= arr2[i]) top2--;
        s1[++top1] = i;
        s2[++top2] = i;
        if (top1 != top2) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", n);
    return 0;
}


