/*************************************************************************
	> File Name: oj505.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 10时48分41秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_N 100000
string arr[MAX_N + 5];

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
