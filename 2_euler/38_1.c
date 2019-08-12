/*************************************************************************
	> File Name: 38_1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 14时20分25秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#define max_n 10000

int digits(int n) {
    return floor(log10(n)) + 1;
}

int calc(int x) {
    int n = 1;
    int ans = 0;
    while (digits(ans) < 9) {
        ans *= (int)pow(10, digits(x * n));
        ans += x * n;
        n++;
    }
    if (digits(ans) - 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    int tmp = ans;
    while (ans) {
        if (num[ans % 10]) return 0;
        num[ans % 10] = 1;
        ans /= 10;
    }
    return tmp;
}

int main() {
    int ans = 0;
    for (int i = 1; i < max_n; i++) {
        int tmp = calc(i);
        if (tmp > ans) ans = tmp;
    }
    printf("%d\n", ans);
    return 0;
}
