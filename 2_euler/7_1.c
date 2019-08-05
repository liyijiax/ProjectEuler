/*************************************************************************
	> File Name: 7.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 15时24分58秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define max_n 200000

int prime[max_n + 5];

//求第100001个素数的值，估算大小在200000以内，素数定理
int main() {
    memset(prime, 0, sizeof(prime)); // memset是按照字节赋值的
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i; // prime[0]作为计数器
            for (int j = 2; j * i <= max_n; j++) {
                prime[j * i] = 1;
            }
        }
    }
    printf("%d\n", prime[10001]);
    return 0;
}
