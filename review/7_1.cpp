/*************************************************************************
	> File Name: 7_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月28日 星期三 22时36分18秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define max_n 200000

int prime[max_n + 5];

int main() {
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            for (int j = 2; j * i < max_n; j++) {
                prime[j * i] = 1;
            }
        }
    }
    cout << prime[10001] << endl;
    return 0;
}
