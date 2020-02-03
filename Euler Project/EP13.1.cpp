/*************************************************************************
	> File Name: EP13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月01日 星期五 18时58分22秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {    
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int ans[50] = {0};
        ans[0] = ans[1] = 1;
        for (int i = 1; i <= m; i++){
            for (int i = 1; i <= ans[0]; i++) {
            ans[i] *= n;
        }
            for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);   
            // if (i == ans[0]) ans[0]++;
            }
     }   

    for (int i = ans[0]; i > 0; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
 }
    return 0;
}
