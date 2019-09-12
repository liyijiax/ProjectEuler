/*************************************************************************
	> File Name: 21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月08日 星期日 14时35分01秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;
#define max_n 10000
typedef long long int1;

int1 prime[max_n + 5] = {0};
int1 sum[max_n + 5] = {0};
int1 cnt[max_n + 5] = {0};

void init() {
    sum[1] = 1, sum[0] = 0;
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            sum[i] = 1 + i;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                int1 a = (pow(prime[j], cnt[i] + 1) - 1) / (prime[j] - 1);
                int1 b = (pow(prime[j], cnt[i] + 2) - 1) / (prime[j] - 1);
                sum[i * prime[j]] = sum[i] * b / a;
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                sum[i * prime[j]] = sum[prime[j]] * sum[i];
                cnt[i * prime[j]] = 1;
            }
        }
    }
}

int main() {
    init();
    for (int i = 2; i <= max_n; i++) {
        sum[i] -= i;
    }
    int1 res = 0;
    for (int i = 2; i <= max_n; i++) {
        int1 a = sum[i];
        if (a > max_n) continue;
        int1 b = sum[a];
        if (b > max_n) continue;
        if (a == i) continue;
        if (b == i) res += i;
    }
    cout << res << endl;
    return 0;
}
