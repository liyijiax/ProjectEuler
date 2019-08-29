/*************************************************************************
	> File Name: 8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月28日 星期三 23时05分07秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cinttypes>
#include "input8.h"
using namespace std;

int main() {
    int64_t zero = 0, p = 1, ans = 0;
    for (int i = 0; num[i]; i++) {
        if (num[i] == '0') zero++;
        else p *= (num[i] - '0');
        if (i >= 13) {
            if (num[i - 13] == '0') zero--;
            else p /= (num[i - 13] - '0');
        }
        if (zero == 0 && ans < p) ans = p;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
