/*************************************************************************
	> File Name: oj281.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月21日 星期三 16时58分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BASE 26
#define BASE_LETTER 'a'
#define MAX_N 1000000

struct Node {
    int flag;
    int next[BASE];
} tree[MAX_N + 5];

int root = 1, cnt = 1;
char str[MAX_N + 5];

int getNewNode() { 
    return ++cnt; 
}

void insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNewNode();
        p = tree[p].next[ind];
    }
    tree[p].flag += 1;
    return ;
}

int query(const char *str) {
    int p = root, cnt = 0; 
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BASE_LETTER;
        p = tree[p].next[ind];
        cnt += tree[p].flag;
    }
    return cnt;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (n--) scanf("%s", str), insert(str);
    while (m--) scanf("%s", str), printf("%d\n", query(str));
    return 0;
}

