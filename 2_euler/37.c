/*************************************************************************
	> File Name: num.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 18时02分11秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#define max_n 1000000


int temp[max_n + 5] = {0};
int prime[max_n + 5] = {0};

void init() {
    temp[1] = 1;
    for (int i = 2; i <= max_n; i++) {
        if (!temp[i]) prime[++temp[0]] = i;
        for (int j = 1; j <= temp[0]; j++) {
            if (i * prime[j] > max_n) break;
            temp[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int is_val(int x) {
    int digit = floor(log10(x)) + 1;
    int tmp = x;
    int h = (int)pow(10, digit - 1);
    for (int i = 0; i < digit - 1; i++) {
        if (temp[tmp / 10]) return 0;
        tmp /= 10;
    }
    tmp = x;
    for (int i = 0; i < digit - 1; i++) {
        if (temp[tmp % h]) return 0;
        h /= 10;
    }
    return 1;
}

int main() {
   init(); 
    int sum = 0;
    int count = 0;
    for (int i = 1; i <= temp[0]; i++) {
        if (is_val(prime[i])){
            int dig = floor(log10(prime[i])) + 1;
            if (dig == 1) continue;
            sum += prime[i];
            printf("-%d\n", prime[i]);
            count++;
        } 
    }
    printf("%d\n", sum);
    printf("%d\n", count);
    printf("%d\n", is_val(11));
    return 0;
}
