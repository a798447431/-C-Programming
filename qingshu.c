/*************************************************************************
	> File Name: qingshu.c
	> Author: 
	> Mail: 
	> Created Time: 2019年04月04日 星期四 15时31分39秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>

const int MAX_LENGTH = 256;

char* get_letter(void) {
    static char letter[1000000];
    letter[999999] = ' ';
    char *p = letter;
    int size = MAX_LENGTH;
    while (feof(stdin) == 0) {
        if (size == 0) {
            break;
        }
        fgets(p, size + 1, stdin);
        while (*p != '\0') {
            p++;
            size--;
        }
    } 
    return letter;
}

int main() {
    char *str = get_letter();    
    // 在此处添加你的代码
    int count = 0;
    char delim[20] = "\n\t ,.\r'\"";
    char love[5] = "love";
    char *str1 = malloc(MAX_LENGTH * sizeof(char));
    strcpy(str1, str);
    char *temp = strtok(str, delim);
    while(temp) {
        printf("%s\n", temp);
        if (!strcmp(str1, love)) {
            count++;
        }
        temp = strtok(NULL, delim);
    }
    printf("%d\n", count);
    free(str1);
    puts(str);
    return 0;
}

#undef MAX_LENGTH
