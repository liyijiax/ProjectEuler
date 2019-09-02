/*************************************************************************
	> File Name: 9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月02日 星期一 18时06分59秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int flag = 1, a, b, c;
    for (int i = 1; i < 32 && flag; i++) {
        for (int j = i + 1; j < 32 && flag; j++) {
            if (gcd(i, j) != 1) continue;
            a = 2 * i * j;
            b = j * j - i * i;
            c = j * j + i * i;
            if (1000 % (a + b + c)) continue;
            flag = 0;
            int e = pow(1000 / (a + b + c), 3);
            cout << e * a * b * c << endl;
        }
    }
    return 0;
}
