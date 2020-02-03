/*************************************************************************
	> File Name: oj328.cpp
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月23日 星期五 19时02分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 200000
int c[MAX_N + 5];

inline int lowbit(int x) { return x & (-x); }
void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}

int query(int x) {
    int sum = 0;
    while (x) sum += c[x], x -= lowbit(x);
    return sum;
}

int main() {
    long long n, a;
    long long ans1 = 0, ans2 = 0;
    cin >> n;
    for (long long  i = 1; i <= n; i++) {
        cin >> a;
        long long val1 = query(a);
        long long val2 = (a - 1 - val1);
        long long val3 = (i - 1 - val1);
        long long val4 = (n - a - val3);
        ans1 += val1 * val2;
        ans2 += val3 * val4;
        add(a, 1, n);
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}
