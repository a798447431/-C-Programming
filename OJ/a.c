/*************************************************************************
	> File Name: 20.UnionSet.c
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月22日 星期四 23时06分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

struct Data {
    int p, d;
}arr[MAX_N + 5];

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

void select_sort(struct Data *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[ind].p > arr[j].p) ind = j;         
        }
        swap(arr[i], arr[ind]);    
    }
    return ;
}



int solve() {
    int n;
    if (!scanf("%d", &n)) return 0;
    for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].p, &arr[i].d);
    quick_sort(arr, 0, n - 1);
    UnionSet *u = init(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (find(u, arr[i].d) == 0) continue;
        ans += arr[i].p;
        int day = find(u, arr[i].d);
        merge(u, day, day - 1);
    }
    printf("%d\n", ans);
    clear(u);
    return 0;
}

int main() {
    while (solve()) ;
    return 0;
}
