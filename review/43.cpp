/*************************************************************************
	> File Name: 43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月31日 星期六 15时14分17秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

long long is_val(int *a) {
    if (a[0] == 0) return 0;
    long long ret = 0, num = 0, j = 0;
    int prime[7] = {2, 3, 5, 7, 11, 13, 17};
    for (int i = 0; i < 10; i++) {
        ret = ret * 10 + a[i];
        num = num * 10 + a[i];
        if (i < 3) continue;
        num -= a[i - 3] * 1000;
        if (num % prime[j++]) return 0;
    }
    return ret;
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    long long sum = 0;
    do {
        sum += is_val(a);
        if (!is_val(a)) continue;
        cout << is_val(a) << endl;
    } while (next_permutation(a, a + 10));
    cout << sum << endl;
    return 0;
}
