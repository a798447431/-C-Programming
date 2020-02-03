/*************************************************************************
	> File Name: 3.城市路径.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月25日 星期五 20时04分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100000
long long arr[MAX_N][2];

struct coor{
    int x, y;
}coor[MAX_N + 5];

int dis(struct coor c1, struct coor c2) {
    return abs(c1.x - c2.x) + abs(c1.y + c2.y);
}

int main() {
    int n, ans;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coor[i].x >> coor[i].y;
    }
    for (int i = 2; i <= n; i++) {
        arr[i][0] = arr[i - 1][0] + dis(coor[i], coor[i - 1]);
    }
    for (int i = 2; i <= n; i++) {
        arr[i][1] = min(arr[i - 1][1] + dis(coor[i], coor[i - 1]), arr[i - 2][0] + dis(coor[i - 2], coor[i]));
    }
    cout << arr[n][1] << endl;
    return 0;
}
