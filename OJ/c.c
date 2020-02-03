/*************************************************************************
	> File Name: 20.UnionSet.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月22日 星期四 23时06分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500000

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
    return u->father[x] = root;
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    u->father[fa] = fb;
    u->val[fa] = u->size[fb];
    u->size[fb] += u->size[fa];
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
    int n;
    scanf("%d", &n);
    UnionSet *u = init(n);
    char str[10];
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%s%d%d", str, &a, &b);
        switch(str[0]) {
            case 'M': merge(u, a, b); break;
            case 'C': {
                if (find(u, a) != find(u, b)) {
                    printf("-1\n");
                } else {
                    printf("%d\n", abs(u->val[a] - u->val[b]) - 1);
                }
            } break;
        }
    }
    clear(u);
    return 0;
}
