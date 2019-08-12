/*************************************************************************
	> File Name: 44.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 15时00分14秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

typedef long long int1;

int1 pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}

int is_Pentagonal(int1 x) {
    int head = 1, tail = 100000;
    while (head <= tail) {
        int mid = (head + tail) >> 1;
        if (pentagonal(mid) == x) return mid;
        else if (pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0; 
}

int main() {
    int1 i = 1, j = 1, ans = INT32_MAX;
    while (pentagonal(j + 1) - pentagonal(j) < ans) {
        j += 1;
        i = j - 1;
        do {
            if (pentagonal(j) - pentagonal(i) > ans) break;
            if (is_Pentagonal(pentagonal(j) + pentagonal(i))) {
                if (is_Pentagonal(pentagonal(j) - pentagonal(i))) {
                    if (pentagonal(j) - pentagonal(i) < ans) {
                        ans = pentagonal(j) - pentagonal(i);
                    }
                }
            }
            i--;
        } while (i >= 1 && pentagonal(j) - pentagonal(i) < ans);
    }
    printf("%lld\n", ans);
    return 0;
}
