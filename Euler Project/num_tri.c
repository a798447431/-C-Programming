/*************************************************************************
	> File Name: num_tri.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年06月25日 星期二 19时28分29秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N + 5
int64_t val[MAX_N + 5][MAX_N + 5];
int64_t mamory[MAX_N + 5][MAX_N + 5];

int64_t access(int64_t i, int64_t j, int64_t n) {
    if (i + 1 == n) return val[i][j];
    if (mamory[i][j] != 0) return mamory[i][j];
    int64_t val1 = access(i + 1, j, n);
    int64_t val2 = access(i + 1, j + 1, n);
    return mamory[i][j] = (val1 > val2 ? val1 : val2) + val[i][j];
}


int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &val[i][j]);
        }
    }
    printf("%" PRId64"\n", access(0, 0, num));
    return 0;
}
