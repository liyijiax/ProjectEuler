/*************************************************************************
	> File Name: 21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 14时13分48秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};
int fac[max_n + 5] = {0};

void init() {
    f[1] = 1;
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 1 + i;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            f[prime[j] * i] = f[i] + f[i] * prime[j];
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    init();
    for (int i = 1; i < max_n; i++) {
        f[i] = f[i] - i;
    }
    for (int i = 2; i < 100; i++) {
        cout << "f[" << i << "]" << "=" << f[i] << endl;
    }
    int sum = 0;
    for (int i = 2; i < max_n; i++) {
        if (f[i] < max_n && f[i] != i && f[f[i]] == i) sum += i;
    }
    cout << sum << endl;
    return 0;
}
