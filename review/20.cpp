/*************************************************************************
	> File Name: 20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月03日 星期二 14时52分56秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 200

int num[max_n + 5] = {0};

int main() {
    num[0] = 1, num[1] = 1;
    for (int j = 2; j <= 100; j++) {
        for (int i = 1; i <= num[0]; i++) {
            num[i] *= j;
        }
        for (int i = 1; i <= num[0]; i++) {
            if (num[i] < 10) continue;
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
            num[0] += (i == num[0]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= num[0]; i++) {
        sum += num[i];
    }
    cout << sum << endl;
    return 0;
}
