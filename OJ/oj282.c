/*************************************************************************
	> File Name: oj282.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月21日 星期三 22时22分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 320000
#define BASE 30

#define max(a, b) (((a)>(b)) ? (a):(b))

struct Node {
    int num;
    int next[2];
} tree[MAX_N + 5];

int root = 1, cnt = 1;
int arr[(MAX_N >> 5) + 5];

int getNewNode() {
    return ++cnt;
}

void insert(int num) {
    int p = root;
    for (int i = BASE; i >= 0; --i) {
        int ind = !!((1 << i) & num);
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNewNode();
        p = tree[p].next[ind];
    } 
    tree[p].num = num;
    return ;
}

int query(int num) {
    int p = root;
    for (int i = BASE; i >= 0; i--) {
        int ind = !!((1 << i) & num);
        int rind = !ind;
        if (tree[p].next[rind]) p = tree[p].next[rind];
        else p = tree[p].next[ind];
    }
    return num ^ tree[p].num;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insert(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, query(arr[i]));
    }
    printf("%d\n", ans);
    return 0;
}

