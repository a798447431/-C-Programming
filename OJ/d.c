/*************************************************************************
	> File Name: d.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月22日 星期四 23时06分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50000

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
    u->val[x] %= 3;
    return u->father[x] = root;
}

int merge(UnionSet *u, int a, int b, int c) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) {
        if ((u->val[a] - u->val[b] + 3) % 3 == c) return 1;
        else return 0;
    }
    u->father[fa] = fb;
    u->size[fb] += u->size[fa];
    u->val[fa] = (c + u->val[b] - u->val[a] + 3) % 3;
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

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    UnionSet *u = init(n);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n || (d == 2 && x == y)) {
            ans++;
            continue;
        }
        if (!merge(u, x, y, d - 1)) ans++;
    }
    printf("%d\n", ans);
    clear(u);
    return 0;
}
