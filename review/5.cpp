/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月28日 星期三 22时25分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int times = 1;
    for (int i = 1; i <= 20; i++) {
        if (times % i == 0) continue;
        times = times * i / gcd(i, times);
    }
    cout << times << endl;
    return 0;
}
