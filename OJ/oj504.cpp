/*************************************************************************
	> File Name: oj504.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 10时09分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int s;
    string n;
    cin >> n >> s;
    for (int i; i = 0, s--; n.erase(i, 1)) {
        while (i < n.length() && n[i] <= n[i + 1]) {
            i++;
        }
        while (n.length() > 1 && n[0] == '0') {
            n.erase(0, 1);
        }
    }
    cout << n << endl;
    return 0;
}
