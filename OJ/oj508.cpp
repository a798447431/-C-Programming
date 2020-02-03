/*************************************************************************
	> File Name: oj508.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 15时02分22秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000
int dp[MAX_N + 5], t[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t + 1, t + n + 1);
    dp[1] = t[1];
    dp[2] = t[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + t[i] + t[1], dp[i - 2] + t[1] + 2 * t[2] +t[i]);
    }
    cout << dp[n] << endl;
    return 0;
}



