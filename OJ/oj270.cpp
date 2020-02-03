/*************************************************************************
	> File Name: oj270.cpp
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月17日 星期三 15时47分55秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX_N 300000
int q[MAX_N + 5], head ,tail;
long long arr[MAX_N + 5] ;

int main() {
    int n, m ;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    head = tail = 0;
    q[tail++] = 0; //存的下标
    long long ans = arr[1];
    for (int i = 1; i <= n; i++) {
        if (arr[i] - arr[q[head]] > ans) {
            ans = arr[i] - arr[q[head]];
        }
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if (q[head] == i - m) head++;
    }
    cout << ans << endl;
    return 0;
}
