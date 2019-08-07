/*************************************************************************
	> File Name: 14_1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月07日 星期三 14时51分40秒
 ************************************************************************/
#include <stdio.h>
#define max_n 10000
#define keep_max_len 10000

int keep[keep_max_len] = {0};

long long get_len(long long x) {
    if (x == 1) return 1;
    if (x < keep_max_len && keep[x]) return keep[x];
    int ret;
    if(x & 1) ret = 1 +  get_len(x * 3 + 1);
    else ret = 1 + get_len(x >> 2);
    if (x < keep_max_len) keep[x] = ret;
    return ret; 
}
int main() {
    int ans = 0;
    int num = 0;
    for (int i = 1; i <= max_n; i++) {
        int l = get_len(i);
        if (l > ans) {
            ans = l;
            num = i;
        }
    }
    printf("%d\n", num);

    return 0;
}
