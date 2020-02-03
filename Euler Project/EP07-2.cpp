/*************************************************************************
	> File Name: EP07-2.cpp
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年06月15日 星期六 14时31分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 200000
int is_prime[MAX_N + 5];

int main() {
    for (int i = 2; i * i <= MAX_N; i +=  1 + (i % 2)) {
        if (is_prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            is_prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) continue;
        is_prime[++is_prime[0]] = i;
    }
    cout << is_prime[10001] << endl;
    return 0;
}
