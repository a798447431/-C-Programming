/*************************************************************************
	> File Name: EP08.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月26日 星期二 20时26分25秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"008.h"

int main(){
    
    int64_t ans = 1, zero = 0, maxN = 0;
    for(int32_t i = 0; i < 1000; ++i){
        if(a[i] != '0'){
            ans *= a[i] - '0';
        }else{
            ++zero;
        }
        if(i >= 13){
            if(a[i - 13] != '0'){
                ans /= a[i - 13] - '0';
            }else{
                --zero;
            }
        }
        if(zero == 0 && ans > maxN) maxN = ans;
    }

    printf("%"PRId64 "\n", maxN);
    return 0;
}


