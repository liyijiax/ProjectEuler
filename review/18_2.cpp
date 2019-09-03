/*************************************************************************
	> File Name: 18_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月03日 星期二 14时19分29秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 15

int num[max_n][max_n] = {0};
int f[max_n][max_n] = {0};

int main() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 0; i < max_n; i++) {
        f[14][i] = num[14][i];
    }
    for (int i = 13; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = f[i + 1][j];
            if (f[i][j] < f[i + 1][j + 1]) 
                f[i][j] = f[i + 1][j + 1];
            f[i][j] += num[i][j];
        }
    }
    cout << f[0][0] << endl;
    return 0;
}
