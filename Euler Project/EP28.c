/*************************************************************************
	> File Name: EP28.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月24日 星期日 17时35分46秒
 ************************************************************************/

#include<stdio.h>
int main(){

    long int len = 3, sum = 1;

    while(len <= 1001){

        sum += 4 * len * len - 6 * len + 6;

        len += 2;

    }

    printf("%ld\n", sum);

    return 0;
}
