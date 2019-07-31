/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 18时25分31秒
 ************************************************************************/

#include<stdio.h>
define N 600851475142LL

int main() {
    long long i = 2, ans = 0, num = N;
    while (i * i <= N) {
        if (num % i == 0) ans = i;// 为什么确定ans一定是质数
        while (num % i == 0) num /= i;
        i++;
    }
    if (num != 1) ans = num; // 为什么要判断n的值
    printf("%d", num);
    return 0; 
}
