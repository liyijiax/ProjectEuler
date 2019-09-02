/*************************************************************************
	> File Name: 12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月02日 星期一 18时50分24秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 100000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }
}

int main() {
    init();
    int ret, i;
    for (i = 2; i <= max_n; i++) {
        if (i & 1) {
            ret = f[(i - 1) >> 1] * f[i];
        } else {
            ret = f[i - 1] * f[i >> 1];
        }
        if (ret > 500) break;
    }
    for (int i = 2; i < 20; i++) {
        cout << i << ":" << f[i] << ":" << cnt[i] << endl;
    }
    cout << (i - 1) * i / 2 << endl;
    return 0;
}
