/*************************************************************************
	> File Name: 8_1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 18时18分44秒
 ************************************************************************/

#include<stdio.h>
#include "8_1.h"

int main() {
    long long ans = 1;
    int count = 0;
    long long max = 1;
    for (int i = 0; num[i]; i++) {
        if (num[i] == 0) {
            count += 1;
        } else {
            ans *= num[i];
        }
        if (i >= 13) {
            if(num[i - 13] == 0) {
                count -= 1;
            } else {
                ans /= num[i - 13];
            }
        }
        if (count == 0 && ans > max) {
            max = ans;
        }
    }
    printf("%lld\n", max);
    return 0;
}
