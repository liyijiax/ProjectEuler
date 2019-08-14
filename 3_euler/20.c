/*************************************************************************
	> File Name: 20.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 16时40分30秒
 ************************************************************************/

#include<stdio.h>

#define max_n 100

int num[10000 + 5] = {0};

int main() {
    num[0] = 1;
    num[1] = 1;
    for (int i = 1; i <= max_n; i++) {
        for (int  j = 1; j <= num[0]; j++) {
            num[j] *= i;
        }
        for (int k = 1; k <= num[0]; k++) {
            if (num[k] < 10) continue;
            num[k + 1] += num[k] / 10;
            num[k] %= 10;
            num[0] += (num[0] == k);
        }
    }
    long long sum = 0;
    for (int i = 1; i <= num[0]; i++) {
        sum += num[i];
    }
    printf("%lld\n", sum);
}
