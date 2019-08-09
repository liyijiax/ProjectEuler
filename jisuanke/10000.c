/*************************************************************************
	> File Name: 10000.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 20时20分02秒
 ************************************************************************/

#include<stdio.h>
#define max_n 10000

int f[max_n + 5] = {1, 1};

int main() {
    int n;
    scanf("%d", &n);
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= f[0]; i++) {
            f[i] *= k;
        }
        for (int j = 1; j <= f[0]; j++) {
            f[j + 1] += f[j] / 10;
            f[j] %= 10;
            f[0] += (j == f[0]);
        }
    }
    for (int i = f[0]; i > 0; i--) {
        printf("%d", f[i]);
    }
    return 0;
}
