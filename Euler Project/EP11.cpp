/*************************************************************************
	> File Name: EP11.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年02月28日 星期四 16时00分52秒
 ************************************************************************/

#include<stdio.h>

int dir[4][2] = {
    0, 1, 1, 1, 1, 0, 1, -1
};





int main(){
    int ans = 0;
    int num[30][30] = {0};
    for (int i = 5; i < 25; i++) {
        for(int j = 5; j  < 25; j++){
            scanf("%d", &num[i][j]);
        }
    }

    for (int x = 5; x < 25; x++) {
        for(int y = 5; y < 25; y++) {
            for(int k = 0; k < 4; k++) {
                int p = 1;
                for(int step = 0; step < 4; step++) {
                    int xx = x + step * dir[k][0];
                    int yy = y + step * dir[k][1];
                    p *= num[xx][yy];
                }
                if(p > ans) ans = p;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

