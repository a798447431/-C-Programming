/*************************************************************************
	> File Name: 3.c
	> Author: suziteng
	> Mail: 253604653@qq.com
	> Created Time: 2019年07月19日 星期五 20时56分10秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int year;
    scanf("%d", &year);
    int start_year = 1900;
	int tmp = 0;
	if (year >= start_year) {
		tmp = (year - start_year) % 12;
	} else if (year <= start_year) {
		tmp = 12 - (start_year - year) % 12;
	}
    switch(tmp) {
        case 0: printf("rat\n"); break;
        case 1: printf("ox\n"); break;
        case 2: printf("tiger\n"); break;
        case 3: printf("rabbit\n"); break;
        case 4: printf("dragon\n"); break;
        case 5: printf("snake\n"); break;
        case 6: printf("horse\n"); break;
        case 7: printf("sheep\n"); break;
        case 8: printf("monkey\n"); break;
        case 9: printf("rooster\n"); break;
        case 10: printf("dog\n"); break;
        case 11: printf("pig\n"); break;
    }
    return 0;
}

