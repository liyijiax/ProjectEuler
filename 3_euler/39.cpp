/*************************************************************************
	> File Name: 39.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 18时09分23秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000

int cnt[max_n + 5] = {0};

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}
int main() {
    for (int n = 1; n <=32; n++) {
        for (int m = n + 1; m <= 32; m++) {
            if (gcd(m, n) - 1) continue;
            int a = 2 * m * n;
            int b = m * m - n * n;
            int c = m * m + n * n;
            for (int p = a + b + c; p <= max_n; p += a + b + c) {
                cnt[p] += 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= max_n; i++) {
        if (cnt[i] > ans) ans = i;
    }
    cout << ans << endl;
    return 0;
}
