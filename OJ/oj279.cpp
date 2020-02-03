/*************************************************************************
	> File Name: oj279.cpp
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月19日 星期一 14时31分47秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000000
#define BASE 31
#define MOD_P 10000009
char str1[(MAX_N << 1) + 5], str2[MAX_N + 5];
int h[(MAX_N << 1) + 5], base[MAX_N + 5];

void init() {
    base[0] = 1;
    for (int i = 0; i < MAX_N; i++) {
        base[i] = base[i - 1] * BASE % MOD_P;
    }
    return ;
}

void init_hash_code(char *str) {
    for (int i = 0; str[i]; i++) {
        h[i + 1] = (h[i] * BASE + str[i]) % MOD_P;
    }
    return ;
}

bool check(char *a, char *b) {
    for (int i = 0; b[i]; i++) {
        if (a[i]- b[i]) return false;
    }
    return true;
}

int main() {
    init();
    scanf("%s%s", str1, str2);
    int len1 = strlen(str1), len = strlen(str2);
    for (int i = 0; i < len1; i++) str1[i + len1] = str1[i];
    init_hash_code(str1);
    long long code = 0, flag = 0;
    for (int i = 0; str2[i]; i++) code = (code * BASE + str2[i]) % MOD_P;
    for (int i = 0; i < len1; i++) {
        long long temp_code = ((h[i + len1] - base[len1] * h[i]) % MOD_P + MOD_P) % MOD_P;
        if (temp_code - code) continue;
        if (!check(str1 + i, str2)) continue;
        flag = 1;
        break;
    }
    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}
