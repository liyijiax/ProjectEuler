/*************************************************************************
	> File Name: 37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月30日 星期五 19时54分42秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init_prime() {
    is_prime[0] = 1, is_prime[1] = 1;
    for (int i = 2; i < max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_val(int x) {
    int tmp = x;
    while (tmp) {
        if (is_prime[tmp]) return 0;
        tmp /= 10;
    }
    int h = pow(10, floor(log10(x)));
    tmp = x;
    while (tmp) {
        if (is_prime[tmp]) return 0;
        tmp -= tmp / h * h;
        h /= 10;
    }
    return 1;
}

int main() {
    init_prime();
    int flag = 11, sum = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] < 10) continue;
        if (!is_val(prime[i])) continue;
        sum += prime[i];
        flag--;
        if (!flag) break;
    }
    cout << sum << endl;
    return 0;
}
