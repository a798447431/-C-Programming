/*************************************************************************
	> File Name: square.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年05月09日 星期四 16时30分44秒
 ************************************************************************/

#include <stdio.h> 
#include <stdlib.h>
/*
#define SQUARE(x) ((x)*(x))

int Square(int x){
    return (x * x); //未考虑溢出保护
}

int main(){
    int i = 1;
    while(i <= 5)
        printf("i = %d, Square = %d\n", i, Square(i++));

    int j = 1;
    while(j <= 5)
        printf("j = %d, SQUARE = %d\n", j, SQUARE(j++));
    
    return 0;
*/
#define NUM OK
int main(){
    struct stu{
        int num;
        char *name;
        char sex;
        float score;
    }*ps;
    ps=(struct stu*)malloc(sizeof(struct stu));
    ps->num = 102;
    ps->name = "Zhang ping";
    ps->sex = 'M';
    ps->score = 62.5;
#ifdef NUM
    printf("Number=%d\nScore=%f\n", ps->num, ps->score); /*--Execute--*/
#else
    printf("Name=%s\nSex=%c\n", ps->name, ps->sex);
#endif
    free(ps);
    return 0;
}
