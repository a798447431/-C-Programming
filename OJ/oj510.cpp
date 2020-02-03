/*************************************************************************
	> File Name: oj510.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 14时01分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAX_N 10000

struct Data {
    int a, b, ind;
    bool operator<(const Data &obj) const {
        if (a - b != obj.a - obj.b) return (a - b) > (obj.a- obj.b);
    }
} arr[MAX_N + 5];

int dp[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].a >> arr[i].b, arr[i].ind = i;
    set<Data> s;
    s.insert(arr[2]);
    dp[2] = arr[1].b + arr[2].a;
    for (int i = 4; i <= n; i += 2) {
        int val1 = dp[i - 2] + arr[i].a + arr[i - 1].b;
        int val2 = dp[i - 2] - s.begin()->a + s.begin()->b + arr[i].a + arr[i - 1].a;
        dp[i] = min(val1, val2);
        if (val1 < val2) {
            s.insert(arr[i]);
        } else {
            s.erase(s.begin());
            s.insert(arr[i]);
            s.insert(arr[i - 1]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
