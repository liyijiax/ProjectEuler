/*************************************************************************
	> File Name: 47_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月08日 星期日 10时44分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void init() {
    for (int i = 2; i < max_n; i++) {
        if (prime[i]) continue;
        for (int j = 2 * i; j < max_n; j += i) {
            prime[j] = 1;
            cnt[j] += 1;
        }
    }
}

int main() {
    init();
    int i;
    for (i = 1; i < max_n; i++) {
        int flag = 1;
        for (int k = 0; k < 4 && flag; k++) {
            flag = (cnt[i + k] == 4);
        }
        if (flag) break;
    }
    cout << i << endl;
    return 0;
}
