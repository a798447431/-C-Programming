/*************************************************************************
	> File Name: oj73.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月22日 星期四 23时06分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_M 1000000

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

#define ind(i, j) ((i) * (m) + (j) + 1)

char str[MAX_N + 5][MAX_N + 5];

typedef struct UnionSet {
    int *father, *size; 
    int n; 
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    u->size = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

int find(UnionSet *u, int x) {
    return u->father[x] = (u->father[x] == x ? x : find(u, u->father[x]));
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] > u->size[fb]) swap(fa, fb);
    u->father[fa] = fb;
    u->size[fb] += u->size[fa];
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
    free(u->size);
    free(u);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n * m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        for (int j = 0; j < m; j++) {
            if (str[i][j] == 'X') continue;
            if (i && str[i - 1][j] == 'O') merge(u, ind(i, j), ind(i - 1, j));
            if (i && str[i][j - 1] == 'O') merge(u, ind(i, j), ind(i, j - 1));
            if (i == 0 || i == n - 1) merge(u, ind(i, j), 0);
            if (j == 0 || j == m - 1) merge(u, ind(i, j), 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str[i][j] == 'X') continue;
            if (find(u, ind(i, j)) - find(u, 0)) ans += 1;
        }
    }
    printf("%d\n", ans);
    clear(u);
    return 0;
}
