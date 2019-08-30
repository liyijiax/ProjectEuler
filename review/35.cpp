/*************************************************************************
	> File Name: 35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月30日 星期五 09时07分16秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init_prime() {
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

int circular(int x) {
    int p = x;
    int l = floor(log10(x));
    int h = pow(10, floor(log10(x)));
    for (int i = 0; i < l; i++) {
        x = x / 10 + (x % 10) * h;
        if (is_prime[x]) return 0;
    }
    return 1;
}

int solve() {
    int count = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (!circular(prime[i])) continue;
        count++;
    }
    return count;
}

int main() {
    init_prime();
    int count;
    count = solve();
    cout << count << endl;
    return 0;
}
