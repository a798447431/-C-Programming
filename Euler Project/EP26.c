/*************************************************************************
	> File Name: EP26.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月06日 星期三 18时20分25秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define max_n 1000

int dnum[max_n + 5];

int get_len(int d) {
    int y = 1, n = 1;//n 代表循环长度
    memset(dnum, 0, sizeof(dnum));
    printf("1 / %d = 0.", d);
    while (y && dnum[y] == 0) {
        dnum[y] = n;
        y = y * 10 % d;
        n++;
    }
    printf("(%d)\n", y ? n - dnum[y] : 0);
    return y ? n - dnum[y] : 0;
}

int main() {
    int max_len = 0, ans = 0;
    for (int d = 2; d < max_n; d++) {
        int temp_len = get_len(d);
        if (temp_len > max_len) {
            max_len = temp_len;
            ans = d;
        }
    }
    printf("%d -> %d\n", ans, max_len);
    return 0;
}
