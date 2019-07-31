/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 16时48分56秒
 ************************************************************************/

#include<stdio.h>
#define N 600851475143LL

int main() {
    long long i = 2, ans = 0, num = N;
    while (i * i <= num) {
        if (num % i == 0) ans = i; // ans获得的值一定是素数
        while (num % i == 0) num /= i;
        i++;
    }
    if (num != 1) ans = num; // 这段代码为什么要判断num的值
    printf("%lld\n", ans);
    return 0;
}
