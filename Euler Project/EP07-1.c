/*************************************************************************
	> File Name: EP07-1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月25日 星期一 19时11分10秒
 ************************************************************************/

#include<stdio.h>
#define MAX 200000

int prime[MAX + 5] = {0};

void init() {
    for (int i = 2; i <= MAX; i++){
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j<= prime[0]; j++) {
            if(prime[j] * i > MAX) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}
int main(){
    init();
    printf("%d\n", prime[10001]);

    return 0;
}
