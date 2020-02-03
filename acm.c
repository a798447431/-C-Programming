/*************************************************************************
	> File Name: acm.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年04月21日 星期日 14时08分49秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int64_t Pentagonnnal(int n) {
    return n * (3 * n - 1) / 2;    
}

int64_t Hexagoal(int n) {
    return n * (2 * n - 1);
}

int erfen(int64_t (*num)(int), int n, int val) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num(mid) == val) return mid;
        if (num(mid) < val) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    int n = 144;
    while (erfen(Pentagonnnal, 2 * n, Hexagoal(n)) == -1) ++n; 
    printf("%d\n", n);
    printf("%" PRId64 "\n", Pentagonnnal(n));
    return 0;
}
