/*************************************************************************
	> File Name: hongdingyi.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月04日 星期六 19时37分30秒
 ************************************************************************/

#include<stdio.h>

#ifdef DEBUG
#define LOG(frm, args...) {\
    printf("[%s : %s : %d]", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n");\
}
#else 
#define LOG(frm, args...) {}
#endif

#define P(a, b) {\
    printf("%s = %d expect = %d\n", #a, a, b); \
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    LOG("%d", MAX(2, 3));
    P(MAX(2, 3), 3);
    P(5 + MAX(3, 4), 9);
    P(MAX(2, MAX(3, 4)), 4);
    P(MAX(2, 3 > 4 ? 3 : 4), 4);
    int a = 7;
    P(MAX(a++, 6), 7);
    P(a, 8);
    return 0;
}
