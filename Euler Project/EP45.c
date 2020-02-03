/*************************************************************************
	> File Name: EP45.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月05日 星期二 11时39分22秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>


int64_t pentagonal(int64_t m) {
    return m * (3 * m - 1) / 2;
}

int64_t hexagonal(int64_t x) {
    return x * (2 * x - 1);
}

int64_t binarry_search(int64_t (*num)(int64_t), int64_t n, int64_t x) {
    int64_t head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num(mid) == x) return mid;
        if (num(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main(){
    int64_t n = 144; 
    while (binarry_search(pentagonal, 2 * n, hexagonal(n)) == -1) n++;
    printf("%" PRId64 "\n", hexagonal(n));
    return 0;
} 
