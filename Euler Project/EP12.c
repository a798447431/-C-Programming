/*************************************************************************
> File Name: EP11.c
> Author: 
> Mail: 
> Created Time: 2019年02月24日 星期日 16时29分39秒
************************************************************************/
//暴力枚举
#include<stdio.h>
#include<math.h>

/*int main(){

    int i = 0;

    int sum = 0;

    int count = 0;

    while(1){

        ++i;

        sum += i;

        for(int j = 1; j <= sqrt(sum); ++j){

            if(sum % j == 0){

                ++count;

            }
        }

        if(2 * count > 501){

            break;

        }

        count = 0;

    }

    printf("%d\n", sum);
*/

int num(int n) {
    return n * (n + 1) / 2;
}

int fac_num(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) cnt += 2;
    }
    return cnt;
}

int main() {
    int n = 1;
    while (fac_num(num(n)) < 500) n++;
    printf("%d\n", num(n));
    return 0;

}
