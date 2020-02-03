/*************************************************************************
	> File Name: EP09.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月24日 星期日 14时28分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){
   /* 1. for(int a = 1; a < 1000; a++){
        for(int b = c; b < 1000; b++){
            for(int c = 1; c < 1000; c++){
                if( (a * a + b * b) == c * c && a + b + c == 1000){
                    if(a < b && b < c){
                        printf("%d * %d * %d = %d\n", a, b, c, a * b * c);
                    }
                }
            }
        }
    }
    
    int c;
    for(int a = 1; a < 1000; a++){
        for(int b = 999; b > a; b--){
            c = 1000 - b - a;
            
            if( (a * a + b * b) == c * c){
                printf("%d * %d * %d = %d\n", a, b, c, a * b * c);
                break;
            }
        }
    }

    return 0;
}
*/
    bool flag = true;
    int32_t a, b, c, e;
    for (int32_t i = 1; i < 32 && flag; ++i) {
        for (int32_t j = i + 1; j <= 32 && flag; ++j) {
            a = j * j - i * i;
            b = 2 * i * j;
            c = i * i + j * j;
            if (1000 % (a + b + c) == 0) {
                e = (int32_t)pow(1000 / (a + b + c), 3);
                printf("%d\n", e * a * b * c);
                flag = false;
            }
        }
    }

    return 0;
}
