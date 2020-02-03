/*************************************************************************
	> File Name: oj264-1.cpp
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月18日 星期四 11时48分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX_N 100000
long long arr[MAX_N + 5];
long long l[MAX_N + 5], r[MAX_N + 5];

int main() {
    int n;
    stack<int> s;
    cin >> n;
    arr[0] = arr[n + 1] = -1;
    for (int i = 1; i <=n ; i++) cin >> arr[i];
    s.push(0);
    for (int i = 1; i <= n; i++) {
        while (arr[s.top()] >= arr[i]) s.pop();
        l[i] = i - s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    s.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (arr[s.top()] >= arr[i]) s.pop();
        r[i] = s.top() - i;
        s.push(i);
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] * (l[i] + r[i] - 1));
    }
    cout << ans << endl;
    return 0;
}

