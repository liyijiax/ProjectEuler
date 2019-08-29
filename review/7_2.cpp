/*************************************************************************
	> File Name: 7_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月28日 星期三 22时41分42秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 200000

int prime[max_n + 5] = {0};

int main() {
    for (int i = 2; i < max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    cout << prime[10001] << endl;
    return 0;
}
