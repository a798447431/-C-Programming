/*************************************************************************
	> File Name: EP30.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月24日 星期日 18时51分26秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 354294

int is_valid(int x) {
    int sum = 0, temp = x;
    while (x) {
        sum += (int)pow(x % 10, 5);
        x /= 10;
    }
    return temp == sum;
}


int main() {
    int sum = 0;
    for(int i = 2; i <= MAX_N; i++) {
        if(!is_valid(i)) continue;
        sum += i;
    }

    printf("%d\n", sum);
    return 0;
}
