/*************************************************************************
	> File Name: oj510_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 14时48分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> q;

int main() {
    int n, x, y, result = 0;
    cin >> n;
    for (int i = n; i; i--) {
        cin >> x >> y;
        result += x; //假设都是机长需要付出的价格
        q.push(x - y); //假设当前人当副手，优先队列中机长和副手价格的差值会排最前面
        if (i % 2 == 0) { 
            result -= q.top(); //前后两个人必有一个是机长，减去副手差额
            q.pop(); //减去工资差额
        }
    }
    cout << result << endl;
    return 0;
}
