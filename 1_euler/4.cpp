/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月27日 星期二 18时43分02秒
 ************************************************************************/

#include<iostream>
using namespace std;

int is_val(int x, int base) {
    int tmp = x;
    int y = 0;
    while (x) {
        y = y * base + x % base;
        x /= base;
    }
    return tmp == y;
}

int main() {
    int ans = 0;
    for (int a = 100; a < 1000; a++) {
        for (int b = ans / a + 1; b <= a; b++) {
            if (is_val(a * b, 10) && ans < a * b) ans = a * b;
        }
    }
    cout << ans << endl;
    return 0;
}
