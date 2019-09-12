/*************************************************************************
	> File Name: 19.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月08日 星期日 14时09分32秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;

int which_day(int y, int m, int d) {
    if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    int w = d + 2 * m + 3 * (m + 1) / 5 + y + floor(y / 4) - floor(y / 100) + floor(y / 400);
    w %= 7;
    return ++w;
}

int main() {
    int cnt = 0, y, m, d;
    for (y = 1901; y < 2001; y++) {
        for (m = 1; m < 13; m++) {
            cnt += (7 == which_day(y, m, 1));
        }
    }
    cout << cnt << endl;
    return 0;
}
