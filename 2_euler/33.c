/*************************************************************************
	> File Name: 33_1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 16时40分35秒
 ************************************************************************/

#include<stdio.h>

int is_hav(int x, int y, int *m) {
    int a[2] = {0};
    int b[2] = {0};
    a[0] = x % 10;
    b[0] = y % 10;
    x /= 10;
    y /= 10;
    a[1] = x;
    b[1] = y;
    int flag = 1;
    if (a[0] == b[0] && a[0] != 0) {
        m[0] = a[1];
        m[1] = b[1];
    } else if (a[0] == b[1] && a[0] != 0) {
        m[0] = a[1];
        m[1] = b[0];
    } else if (a[1] == b[0] && a[1] != 0) {
        m[0] = a[0];
        m[1] = b[1];
    } else if (a[1] == b[1] && a[1] != 0) {
        m[0] = a[0];
        m[1] = b[0];
    } else {
        flag = 0;
    }
    return flag;
}


int main() {
    int m[2] = {1, 1};
    int res[2] = {1, 1};
    int product = 1;
    for (int a = 10; a < 100; a++) {
        for (int b = a+1; b < 100; b++) {
            if (!is_hav(a, b, m)) continue;
            if (a * m[1] != b * m[0]) continue;
            printf("%d %d\n", a, b);
            printf("%d %d\n", m[0], m[1]);
            
            res[0] *= m[0];
            res[1] *= m[1];
        }
    }
    for (int i = 2; i <= res[0]; i++) {
        if (res[0] % i == 0 && res[1] % i == 0) {
            while ((res[0] % i == 0) && (res[1] % i == 0)){
                res[0] /= i;
                res[1] /= i;
            }
        }
    }
    printf("%d\n", res[1]);
}
