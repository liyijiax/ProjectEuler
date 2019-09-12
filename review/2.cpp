/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月08日 星期日 16时28分51秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 4000000

int main() {
    int a = 1, b = 1, sum = 0;
    while (a + b < max_n) {
        b += a;
        a = b - a;
        if (b & 1) continue;
        sum += b;
    }
    cout << sum << endl;
    return 0;
}
