/*************************************************************************
	> File Name: 9_1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 19时12分49秒
 ************************************************************************/

#include<stdio.h>
#define max_n 2000000

int temp[max_n] = {0};

int main() {
    long long sum = 0;
    for (int i = 2; i <= max_n; i++) {
        if (!temp[i]) temp[++temp[0]] = i;
        for (int j = 1; j <= temp[0]; j++) {
            if (temp[j] * i > max_n) break;
            temp[temp[j] * i] = 1;
            if (i % temp[j] == 0) break;
        }
    }
    for (int i = 1; i <= temp[0]; i++) {
        sum += temp[i];
    }
    printf("%lld\n", sum);
}
