/*************************************************************************
	> File Name: 寻找666.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月24日 星期日 09时13分09秒
 ************************************************************************/

#include<stdio.h>

int whichDay(int y, int m, int d) {
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return w;
}


int main() {
    int y1, m1, d1;
    scanf("%d %d %d", &y1, &m1, &d1);
    int y2, m2, d2;
    scanf("%d %d %d", &y2, &m2, &d2);
    int ans = 0;
    for (int i = y1; i <= y2; i++) {
        if (whichDay(i, 6, 6) == 5) {
            ans++;
            printf("%d\n", i);
        }
    }

    if (whichDay(y1, 6, 6) == 5 && (m1 > 6 || (m1 == 6 && d1 > 6))) ans--;
    if (whichDay(y2, 6, 6) == 5 && (m2 < 6 || (m2 == 6 && d2 < 6))) ans--;
    printf("%d\n", ans);
    return 0;
}
