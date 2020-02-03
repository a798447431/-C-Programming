/*************************************************************************
	> File Name: oj270-1.cpp
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月18日 星期四 10时59分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 300000
long long q[MAX_N + 5], head, tail;
long long arr[MAX_N + 5];

int main() {
    long long  n, m, ans;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    head = tail = 0;
    q[tail++] = 0; //压入０,元素下标
    ans = arr[1];
    for (long long i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while (tail - head && arr[q[tail - 1]] >= arr[i] ) tail--;
        q[tail++] = i;
        if (q[head] == i - m) head++;
    }
    cout << ans << endl;
    return 0;
}
