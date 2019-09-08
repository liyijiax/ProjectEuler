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
    int p;
    for (int i = 1; i < max_n; i++) {
        if (cnt[i] == 4){ 
            if (cnt[i + 1] == 4) { 
                if (cnt[i + 2] == 4) { 
                    if (cnt[i + 3] == 4) {
                        p = i;
                        break;
                    }
                }
            }
        }
    }
    cout << p << endl;
    return 0;
}
