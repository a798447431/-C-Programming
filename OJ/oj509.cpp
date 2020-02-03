/*************************************************************************
	> File Name: oj509.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 10时12分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 500

struct competitor {
    int time;
    int value;
}arr[MAX_N + 5];

int recode[MAX_N + 5];

bool cmp(const competitor &a, const competitor &b) {
    return a.value > b.value;
}

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].time;
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].value;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = arr[i].time; j >= 1; j--) {
            if (recode[j] == 0) {
                recode[j] = 1;
                break;
            }
            if (j == 1 && recode[j] == 1) {
                m -= arr[i].value;
                break;
            }
        }
    }
    cout << m << endl;
    return 0;
}

