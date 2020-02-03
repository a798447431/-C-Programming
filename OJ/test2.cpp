/*************************************************************************
	> File Name: test2.cpp
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月17日 星期三 18时19分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 300000
int q[MAX_N + 5], head, tail;
long long arr[MAX_N + 5];

int main() {
    int n, m;
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    head = tail = 0;
    q[tail++] = 0;
    long long ans = arr[1];
    for (int i = 1; i <= n; i++) {
        while (arr[i] - arr[q[head]] > ans) ans = arr[i] - arr[q[head]];
        if (tail - head && arr[q[tail] - 1] >= arr[i]) tail--;
        q[tail++] = i;
        if (q[head] == i - m) head--;
    }
    cout << ans << endl;
    return 0;
}
