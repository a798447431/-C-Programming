/*************************************************************************
	> File Name: EP07.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月23日 星期六 19时18分28秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 200000 

/* bao li qiu jie

int Prime(long int j){

    int i, k =0;

    for(i = 2; i<=sqrt(j); ++i){

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
    int i = 1;

    long int j = 2;

    while(i != 10001){
        
        ++j;
        
        if(Prime(j) == 1){
           
            i++;

        }
    
    }

    printf("%ld\n", j);

    return 0;
}

*/


 

// su shu shai 

int prime[MAX + 5] = {0};


void init() {
    for (int i = 2; i * i <= MAX; i++){
            for(int j = i * i; j <= MAX; j += i){
                prime[j] = 1;
             }
     }
    for(int i = 2; i <= MAX; i++){
        if (prime[i]) continue;
        prime[++prime[0]] = i; //***//
       // prime[0] += 1;
       // prime[prime[0]] = i;
    }
    return ;
}



int main(){
    init();
    printf("%d\n", prime[10001]);
    return 0;
}



