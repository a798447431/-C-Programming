/*************************************************************************
	> File Name: log+P+MAX.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月05日 星期日 19时36分21秒
 ************************************************************************/
#include <stdio.h>

#ifdef DEBUG
#define log(fmt, args...) { \
    printf("[%s : %s] %d (%s) : ", __FILE__, __func__, __LINE__, #args); \
    printf(fmt, ##args); \
    printf("\n"); \
}

#else
#define log(fmt, args...)
#endif

#ifdef DEBUG
#define P(a) { \
    printf("%s = %d\n", #a, a); \
}
#else
#define P(a)
#endif
 
#define MAX(a, b) ({ \
    __typeof(a) __a = (a); \
    __typeof(b) __b = (b); \
    (__a) > (__b) ? (__a) : (__b); \
})

int main() {
    int a = 5, b = 6;
    log("%d %d", a, b);
    P(MAX(a, b));
    return 0;
}

 
