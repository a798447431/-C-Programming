/*************************************************************************
	> File Name: oj506.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 11时19分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
#define MAX_N 2000
struct wait_person {
    int seq;
    int time;
} arr[MAX_N + 5];

bool cmp(const wait_person &a, const wait_person &b) {
    if (a.time == b.time) return a.seq < b.seq;
    else return a.time < b.time;
}

int main() {
    int n;
    double sum_t = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        arr[i].seq = i;
        cin >> arr[i].time;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        sum_t += (n - i) * arr[i].time;
        cout << arr[i].seq;
        if (i != n) cout << " ";
    }
    cout << endl;
    printf("%.2f\n", sum_t / n);
    return 0;
}
