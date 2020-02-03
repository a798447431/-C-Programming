/*************************************************************************
	> File Name: test2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月21日 星期四 16时38分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1) { return 0; }
    int type = (argv[1][1] == 'd');
    FILE *fin = stdin;
    FILE *fout = stdout;
    if (argc >= 3) {
        fin = fopen(argv[2], "r");
    }
    if (argc == 4) {
        fout = fopen(argv[3], "w");
    }
    char str[1000];
    int line_no = 1;
    while (fscanf(stdin, "%[^\n]s", str) != EOF) {
        if (type) {
            fprintf(fout, "%d\t%s\n", line_no++, str);
        }
        str[0] = 0;
    }
    return 0;
}
