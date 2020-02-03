/*************************************************************************
	> File Name: EP18.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月18日 星期一 14时46分23秒
 ************************************************************************/

#include<stdio.h>
#define max_n 15

int map[max_n + 5][max_n + 5] = {0};

int solve(int i, int j) {
    if (i == max_n) return 0;
    int lnum = solve(i + 1, j), rnum = solve(i + 1, j + 1);
    return (lnum > rnum ? lnum : rnum) + map[i][j];
}


int main() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j < max; j++) {
            scanf("%d", map[i] + j);
        }
    }    
    printf("%d\n", solve(0, 0));
    return 0;
}
