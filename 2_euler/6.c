/*************************************************************************
	> File Name: 6.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 15时34分34秒
 ************************************************************************/

#include<stdio.h>

// 求1~20的最小公倍数
int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a); 
}
int main() {
    int ans = 1;
    for (int i = 1; i <= 20; i++) {
        if (ans % i == 0) continue;
        ans = ans * i / gcd(ans, i);
    }
}
