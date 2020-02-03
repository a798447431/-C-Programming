/*************************************************************************
	> File Name: 最大因子和.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月23日 星期六 18时09分41秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 1000000

int prime[max + 5] = {0};
int dnum[max + 5] = {0};
int mnum[max + 5] = {0};

void init() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = i + 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (1 - pow(prime[j], mnum[i] + 1)) * (1 - pow(prime[j], mnum[i] + 2));
                break;
            } else {
                    mnum[i * prime[j]] = 1;
                    dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
}

int main() {
    init();
    int ans = 0;
    for (int i = 1; i <= max; i++) {
        if (dnum[i] > ans) ans = dnum[i];
    }
    printf("%d\n", ans);
    return 0;
}
