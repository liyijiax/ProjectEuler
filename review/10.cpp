/*************************************************************************
	> File Name: 10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月29日 星期四 08时29分58秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 2000000

int prime[max_n + 5] = {0};

int main() {
    long long sum = 0;
    for (int i = 2; i < max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i, sum += i;
        for(int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    cout << sum << endl;
    return 0;
}
