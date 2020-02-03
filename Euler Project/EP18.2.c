/*************************************************************************
	> File Name: EP18.2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月06日 星期三 11时19分01秒
 ************************************************************************/

#include<stdio.h>
#define max_n 15
#define max(a, b) ((a) > (b) ? (a) : (b))

int keep[max_n + 5][max_n + 5] = {0};



int main() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", keep[i] + j);
        } 
    }
    for (int i = 13; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            keep[i][j] += max(keep[i + 1][j], keep[i + 1][j + 1]);
        }
    }
    printf("%d\n", keep[0][0]);
    return 0;
}
