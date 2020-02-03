/*************************************************************************
	> File Name: oj507.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 13时00分55秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 50000

struct student{
    int influence;
    int affordability;
    int seq;
}arr[MAX_N + 5];

bool cmp(const student &a, const student &b) {
    return a.seq < b.seq;
}

int main() {
    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].influence >> arr[i].affordability;
        arr[i].seq = i;
    }
    sort(arr + 1, arr + n + 1, cmp);
    int sum = 0 - arr[1].affordability, ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += arr[i].influence;
        sum = max(sum, ans - arr[i].affordability);
    }
    cout << sum << endl;
    return 0;
}

