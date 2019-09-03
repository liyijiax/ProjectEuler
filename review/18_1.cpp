/*************************************************************************
	> File Name: 18.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月03日 星期二 14时05分47秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
using namespace std;
#define max_n 15

int num[max_n][max_n] = {0};
int rem[max_n][max_n] = {0};

int fmax(int i, int j) {
    if (i == max_n) return num[i][j];
    if (rem[i][j]) return rem[i][j];
    int l = num[i][j] + fmax(i + 1, j);
    int r = num[i][j] + fmax(i + 1, j + 1);
    rem[i][j] = l > r ? l : r;
    return rem[i][j];
}

int main() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    cout << fmax(0, 0) << endl;
    return 0;
}
