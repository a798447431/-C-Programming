/*************************************************************************
	> File Name: EP20.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月06日 星期三 12时34分16秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int32_t ans[500] = {0};

int32_t main() {
    ans[0] = ans[1] = 1;
    for (int32_t i = 2; i <= 100; ++i) {
        for (int32_t j = 1; j <= ans[0]; ++j)
        ans[j] *= i;
        for (int32_t j = 1; j <= ans[0]; ++j) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            if (j == ans[0]) ++ans[0];
        }
    }
    int32_t sum = 0;
    for (int32_t j = 1; j <= ans[0]; ++j)
        sum += ans[j];
    printf("%d\n", sum);
    return 0;
}
