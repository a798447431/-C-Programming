/*************************************************************************
	> File Name: testarray.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月07日 星期二 15时04分02秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int func_1(int *a) {
    printf("sizeof(*a) = %lu\n", sizeof(a));
    return 0;
}

int func_2(int (*a)[200]) { //方便校验
    
    return 0;
}

int main() {
    int arr[100][200];
    func_2(arr);
    printf("&arr[0] = %p, arr = %p\n", &arr[0], arr);
    printf("arr + 1 = %p, arr + 2 = %p\n", arr + 1, arr + 2);
    char *p = (char *)arr;
    printf("p + 1 = %p, p + 2 = %p\n", p + 1, p + 2);
    printf("sizeof(arr) = %lu\n", sizeof(arr));
    printf("%" PRId64"\n", INT64_MAX);
    return 0;
}
