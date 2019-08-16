/*************************************************************************
	> File Name: 47.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 19时27分12秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

bool is_val(int x) {
    int tmp = x;
    int cnt = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (x % prime[i] == 0) {
            cnt++;
            while (x % prime[i] == 0) {
                x /= prime[i];
            }
        }
    }
    if (cnt == 4){
        //cout << tmp << endl;
        return true;
    }
    return false;
}

int main() {
    init();
    for (int i = 2; i < max_n; i++) {
        if (!is_val(i)) continue;
        if (!(is_val(i + 1) && is_val(i + 2) && is_val(i + 3))) continue;
        cout << i << endl;
        break;
    }
    //for (int i = 1; i <= prime[0]; i++) cout << prime[i] << endl;
    return 0;
}
