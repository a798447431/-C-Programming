/*************************************************************************
	> File Name: OJ255.cpp
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年06月29日 星期六 20时12分52秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
#define MAX_N 1000

struct Range {
    double l, r;
} arr[MAX_N + 5];

bool cmp(const Range &a, const Range &b) {
    if (a.r - b.r) return a.r < b.r;
    return a.l > b.l;
}

int main() {
    int n;
    double d;
    int flag = 0;
    scanf ("%d%lf", &n, &d);

    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        if (y > d) flag = 1;
        arr[i].l = x - sqrt(d * d - y * y);
        arr[i].r = x + sqrt(d * d - y * y);
    }
    
    if (flag == 1) {
        printf("-1\n");
        return 0;
    }

    sort(arr, arr + n, cmp);
    int ans = 0;
    double p = arr[0].l - 1;
    for (int i = 0; i < n; i++) {
        if (arr[i].l > p) {
            p = arr[i].r;
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
