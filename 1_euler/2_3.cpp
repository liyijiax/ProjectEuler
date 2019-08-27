/*************************************************************************
	> File Name: 2_3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月27日 星期二 14时59分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 4000000

int main() {
    int a = 1, b = 2;
    int sum = 2;
    while (a + b < max_n) {
        b = a + b;
        a = b - a;
        if (b & 1) continue;
        sum += b;
    }
    cout << sum << endl;
    return 0;
}
