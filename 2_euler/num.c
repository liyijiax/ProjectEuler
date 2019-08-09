/*************************************************************************
	> File Name: num.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 18时02分11秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000


int temp[max_n + 5] = {0};
int prime[max_n + 5] = {0};

int is_val(int x) {
    int digit = floor(log10(x)) + 1;
    int tmp = x, h = (int)pow(10, digit - 1);
    for (int i = 0; i < digit; i++) {
        tmp = (tmp % 10) * h + tmp / 10;
        if (temp[tmp]) return 0;
    }
    return 1;
}

int main() {
    temp[0] = 0;
    for (int i = 2; i <= max_n; i++) {
        if (!temp[i]) prime[++temp[0]] = i;
        for (int j = 1; j <= temp[0]; j++) {
            if (i * prime[j] > max_n) break;
            temp[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    int count = 0;
    for (int i = 1; i < temp[0]; i++) {
        if (is_val(prime[i])) count++;
    }
    for (int i = 1; i <= temp[0]; i++) {
        printf("%d\n", temp[i]);
    }
    return 0;
}
