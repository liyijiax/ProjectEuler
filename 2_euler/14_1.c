/*************************************************************************
	> File Name: 14_1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月07日 星期三 14时51分40秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000

int get_len(long long x) {
    if (x == 1) return 1;
    if(x & 1) return 1 +  get_len(x * 3 + 1);
    else return 1 + get_len(x / 2);
}
int main() {
    long long ans = 0;
    long long num = 0;
    for (long long i = 1; i <= max_n; i++) {
        long l = get_len(i);
        if (l > ans) {
            ans = l;
            num = i;
        }
    }
    printf("%lld\n", num);

    return 0;
}
