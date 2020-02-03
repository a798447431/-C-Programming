/*************************************************************************
	> File Name: test3.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月21日 星期四 18时04分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    FILE *input = stdin;
    FILE *out = stdout;
    int figure = 0, roman_num = 0;
    if (argc == 1) return 0;
    if (argv[1][1] == 'd') {
        figure++;      
    }else if (argv[1][1] = 'r') {
        roman_num++;
    }
    if (argc >= 3) {
        input = fopen(argv[2], "r");
    }
    if (argc == 4) {
        out = fopen(argv[3], "w");
    }

    char str[1000];
    int count = 1;
    while(fgets(str, 1000, input) != NULL) {
        if (figure) {
            fprintf(out, "%d\t%s", count++, str);
        }
    return 0;
}
