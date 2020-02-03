/*************************************************************************
	> File Name: EP13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月01日 星期五 18时58分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>

int main() {
 /* char w[55];
    int32_t ans[100] = {0}, len;
    for (int t = 0; t < 100; t++) {
        scanf("%s", w);
        len = strlen(w);
        if (len > ans[0]) ans[0] = len;
        for(int i = len - 1; i >= 0; --i) {
            ans[len - i] += w[i] - '0';
        }
    }

    for(int i = 1; i <= ans[0]; ++i) {
        if (ans[i] >= 10){
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (i + 1 > ans[0]) ans[0] = i + 1;
        }
    }
    
    for (int i = ans[0]; i > ans[0] - 10; --i) {
        printf("%d", ans[i]);
    }
    printf("\n");
*/

    
    char read_num[55];
    int ans[55] = {0};
    while (scanf("%s", read_num) != EOF) {
        int len = strlen(read_num);
        if (len > ans[0]) ans[0] = len;
        for (int i = 0; read_num[i]; i++) {
            ans[len - i] += read_num[i] - '0';
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
                ans[0] += (i == ans[0]);   
               // if (i == ans[0]) ans[0]++;
        }
    }
    
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }

    printf("\n");

    return 0;
}
