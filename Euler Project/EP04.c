/*************************************************************************
	> File Name: EP04.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月18日 星期一 19时28分43秒
 ************************************************************************/

#include<stdio.h>

int is_valid(int x){
   
    int temp = x, num = 0;
    
    while(x){
       
        num = num * 10 + x % 10;
       
        x = x / 10;
    }

    return temp == num;

}



int main(){

int ans = 0;

    for(int i = 100; i <= 999; i++){

        for(int j = ans / i + 1; j<= i; j++){ // !! 归一化
            
            if(!is_valid(i * j)) continue;

            if(ans >= i * j) continue;
    
            printf("%d * %d = %d\n", i , j , i * j);
            
            ans = i * j;
        
         }
    }
    printf("%d\n", ans);
   
    return 0;

}
