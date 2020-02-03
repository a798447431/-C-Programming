/*************************************************************************
	> File Name: EP10.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月24日 星期日 15时11分07秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 2000000


int Prime(long int j){

    int i, k = 0;
    
    for(i = 2; i <= sqrt(j); ++i){

        if(j % i == 0){

            k++;

            break;

        }

    }

    if(k != 0){
        
        return 0;

    }

    else{

        return 1;

    }

}


int main(){
    
    long int j = 1;

    long int sum = 0;

    while(j < MAX_N){

        ++j;
        
        if(Prime(j) == 1) {

            sum += j;

        }
    }

    printf("%ld\n", sum);

    return 0;

}
