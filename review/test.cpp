/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月30日 星期五 19时50分07秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;

void test1(int m) {
    int h = log10(m);
    cout << h << endl;
    int tmp = m;
    tmp -= tmp / pow(10, h) * pow(10, h);
    cout << tmp << endl;
}

int main() {
    int m = 29;
    test1(m);
    return 0;
}
