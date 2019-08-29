/*************************************************************************
	> File Name: 32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月29日 星期四 23时12分10秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;

int digits(int x) {
    return (log10(x) + 1);
}

int add_num(int x, int *num) {
    while (x) {
        if (num[x % 10]) return 0;
        num[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int is_val(int a, int b, int c) {
    if (digits(a) + digits(b) + digits(c) - 9) return 0;
    int num[10] = {0};
    num[0] = 1; 
    int flag = 1;
    flag = flag && add_num(a, num);
    flag = flag && add_num(b, num);
    flag = flag && add_num(c, num);
    return flag;
}

int keep[100000] = {0};

int main() {
    int sum = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = a + 1; b < 10000; b++) {
            if (!is_val(a, b, a * b)) continue;
            if (keep[a * b]) continue;
            sum += a * b;
            keep[a * b] = 1;
        }
    }
    cout << sum << endl;
    return 0;
}
