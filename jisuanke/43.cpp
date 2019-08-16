/*************************************************************************
	> File Name: 43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 19时27分22秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cinttypes>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long num[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);
        }
    }
    printf("%lld",num[0][0]);
    return 0;
}
