/*************************************************************************
	> File Name: 12.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 14时21分23秒
 ************************************************************************/

#include<stdio.h>

#define max_n 10000

int prime[max_n] = {0};
void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; i++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    int f_max = 0, n = 1;
    while (1) {
        if (n & 1) {
            f_max = f[n] * f[(n + 1) >> 1];
        } else {
            f_max = f[n >> 1] * f[n + 1];
        }
        if (f_max > 500) break;
        n += 1;
    }
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
