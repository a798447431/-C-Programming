/*************************************************************************
	> File Name: test1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月21日 星期四 16时07分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main() {
 	char str[1000];
    int line_no = 1;
    while (fscanf(stdin, "%[^\n]s", str) != EOF) {
        fprintf(stdout, "%d\t%s\n", line_no++, str);
    }
    return 0;    
}
















