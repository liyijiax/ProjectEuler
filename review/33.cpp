/*************************************************************************
	> File Name: 33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月30日 星期五 19时35分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int is_val(int a, int b) {
    int x = a, y = b;
    int x1 = a / 10, x2 = a % 10;
    int y1 = b / 10, y2 = b % 10;
    if (x1 == y1 && x2 * y == y2 * x && x1 != 0) return 1;
    else if (x1 == y2 && x2 * y == y1 * x && x1 != 0) return 1;
    else if (x2 == y1 && x1 * y == y2 * x && x2 != 0) return 1;
    else if (x2 == y2 && x1 * y == y1 * x && x2 != 0) return 1;
    else return 0;
}

int main() {
    int x = 1, y = 1;
    for (int i = 10; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (!is_val(i, j)) continue;
            x *= i;
            y *= j;
            int m = gcd(x, y);
            x /= m;
            y /= m;
        }
    }
    cout << y << endl;
    return 0;
}
