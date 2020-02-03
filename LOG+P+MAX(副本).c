/*************************************************************************
	> File Name: LOG+P+MAX.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月14日 星期二 18时02分50秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>

#define DEBUG

#ifdef DEBUG
#define LOG(frm, args...) { \
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__); \
    printf(frm, ##args); \
    printf("\n"); \
}
#else
#define LOG(frm, args...) {}
#endif

#define __P(a, b, str, f) printf("%s = %" f "  expect = %" f "\n", str, a, b) 

#define P(a, b) _Generic((b), \
    int : __P(a, b, #a, "d"), \
    float : __P(a, b, #a, "f"), \
    default : __P(a, b, #a, "lf") \
)

#define MAX(a, b) ({ \
    __typeof(a) temp_a = (a), temp_b = (b); \
    temp_a > temp_b ? temp_a : temp_b; \
})

void test_sscanf_sprintf() {
    char str[1000] = "123 456 789 987";
    int a, b, c, d;
    sscanf(str, "%d%[^$]s", &a, str);
    sscanf(str, "%d%[^$]s", &b, str);
    sscanf(str, "%d%[^$]s", &c, str);
    sscanf(str, "%d%[^$]s", &d, str);
    int offset = 0;
    offset += sprintf(str + offset, "a = %d", a);
    offset += sprintf(str + offset, " b = %d", b);
    offset += sprintf(str + offset, " c = %d", c);
    offset += sprintf(str + offset, " d = %d", d);
    LOG("%s", str);
}

int main() {
    test_sscanf_sprintf();
    int arr[100];
    memset(arr, 2, sizeof(arr));
    LOG("%d %X", arr[0], arr[0]);
    LOG("%d", MAX(2, 3));
    P(MAX(2, 3), 3);
    P(5 + MAX(3, 4), 9);
    P(MAX(2, MAX(3, 4)), 4);
    P(MAX(2, 3 > 4 ? 3 : 4), 4);
    int a = 7;
    P(MAX(a++, 6), 7);
    P(a, 8);
    double aa = 2.3, bb = 4.6;
    P(MAX(aa, bb), 4.6);
    return 0;
}
