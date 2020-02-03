/*************************************************************************
	> File Name: e.cpp
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月23日 星期五 17时06分04秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define MAX_N 100000

using namespace std;

struct Data {
    int a, b;
    long long c;
} arr[MAX_N + 5];

typedef struct UnionSet {
    int *father, *size, *val; 
    int n; 
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    u->size = (int *)malloc(sizeof(int) * (n + 1));
    u->val = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
        u->val[i] = 0;
    }
    return u;
}

int find(UnionSet *u, int x) {
    if (u->father[x] == x) return x;
    int root = find(u, u->father[x]);
    u->val[x] += u->val[u->father[x]];
    u->val[x] %= 2;
    return u->father[x] = root;
}

int merge(UnionSet *u, int a, int b, int c) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    u->father[fa] = fb;
    u->val[fa] = (c + u->val[b] - u->val[a] + 2) % 2;
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
    free(u->size);
    free(u->val);
    free(u);
    return ;
}

bool cmp(const Data &a, const Data &b) {
    return a.c > b.c;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    //先进行实现冲突判断，若m = 0，直接输出0;
    if (m == 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%lld", &arr[i].a, &arr[i].b, &arr[i].c);
    }
    sort(arr, arr + m, cmp);
    for (int i = 0; i < m; i++) {
        if (find(u, arr[i].a) == find(u, arr[i].b)) {
            if (u->val[arr[i].a] == u->val[arr[i].b]) {
                printf("%lld\n", arr[i].c);
                return 0;
            }
        } else {
            merge(u, arr[i].a, arr[i].b, 1);
        }
    }
    printf("0\n");
    clear(u);
    return 0;
}

