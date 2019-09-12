/*************************************************************************
	> File Name: 41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月11日 星期三 21时51分34秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define max_n 1000
typedef long long ll;

ll prime[max_n] = {0};
int hav[10];

void init() {
    for (int i = 2; i < max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int is_val(ll x) {
    memset(hav, 0, sizeof(hav));
    while (x) {
        if (hav[x % 10]) return 0;
        hav[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int main() {
    init();
    ll max = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (!is_val(prime[i])) continue;
        max = prime[i];
    }
    cout << max << endl;
    return 0;
}

