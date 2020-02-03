/*************************************************************************
	> File Name: EP02.2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月18日 星期一 13时33分37秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 4000000
int main(){
    int a = 1, b = 1, c, ans = 0;
   
    while(b <= MAX_N){
       
        if((b & 1) == 0){
           
            ans += b;

        }

     /* c = a + b;

        a = b;

        b = c;
     */

        a = a + b;
       
        a ^= b;
       
        b ^= a;
       
        a ^= b;

    }

    printf("%d\n", ans);

    return 0;
}
