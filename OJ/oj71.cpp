/*************************************************************************
	> File Name: oj71.cpp
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月21日 星期三 20时03分58秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5], size[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            size[i] = 1;
        }
    }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        if (size[aa] < size[bb]) swap(aa, bb);
        fa[bb] = aa;
        size[aa] += size[bb];
        return ;
    }
};

UnionSet u;

void read(int &n, int &m) {
    cin >> n >> m;
    u.init(n);
    return ;
}

int main() {
    int n, m;
    read(n, m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            u.merge(b, c);
        } else {
            cout << (u.get(b) == u.get(c) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
