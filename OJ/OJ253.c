/*************************************************************************
	> File Name: OJ253.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年06月29日 星期六 19时00分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 2500

int cnt[MAX_N + 5];

struct Range{
    int x, y;
} arr[MAX_N + 5];

bool cmp(const Range &a, const Range &b) {
    if (a.y - b.y) return a.y < b.y;
    return a.x > b.x;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &arr[i].x, &arr[i].y);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", a, b);
        cnt[a] += b;
    }
    sort(arr, arr + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int flag = -1;
        for (int j = arr[i].x; j <= arr[i].y && flag == -1; j++) {
            if (cnt[j] == 0) continue;
            flag = j;
        }
        if (flag != -1) cnt[flag] -= 1; ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
