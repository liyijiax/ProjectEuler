/*************************************************************************
	> File Name: 47.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月08日 星期日 10时30分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};

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

int is_val(int x) {
    int cnt = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] > x) break;
        if (x % prime[i]) continue;
        cnt++;
        while (x % prime[i] == 0) {
            x /= prime[i];
        }
    }
    return (cnt == 4);
}

int main() {
    init();
    int p = 0;
    for (int i = 1; i < max_n; i++) {
        if (is_val(i) && is_val(i + 1) && is_val(i + 2) && is_val(i+ 3)) {
            p = i;
            break;
        }
    }    
    cout << p << endl;
    return 0;
}
