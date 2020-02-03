/*************************************************************************
	> File Name: EP03.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月18日 星期一 16时54分20秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define NUM 600851475143

int main() {
   /* int64_t num = 600851475143, x = 2, ans;
    while(x * x <= num) {
        if(num % x) {
            x++;
            continue;
        }

        ans = x;
        while(num % x == 0) num /= x;
        x += 1;
    }
    if (num - 1) ans = num;
    printf("%" PRId64 "\n", ans);*/

    int64_t num = NUM;
    int64_t max_prime;
    for(int64_t i = 2; i * i <= NUM; ++i) {
        while (num % i == 0) {
            num /= i;
            max_prime = i;
        }
    }

    if(num != 1) max_prime = num;
    printf("%"PRId64"\n", max_prime);
    return 0;
}
