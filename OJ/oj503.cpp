/*************************************************************************
	> File Name: oj503.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 21时48分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#define MAX_N 30000
using namespace std;

int arr_w[MAX_N + 5];
int get_rated_capacity(int head, int tail, int max_w) {
    int ans = 0;
    while (head <= tail) {
        if (arr_w[tail] > max_w - arr_w[head]) {
            ans += 1;
            tail--;
        } else {
            ans += 1;
            head++, tail--; 
        }
    }
    return ans;
}

int main() {
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr_w[i];
    }
    sort(arr_w, arr_w + n);
    cout << get_rated_capacity(0, n - 1, w) << endl;
    return 0;
}
