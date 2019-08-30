/*************************************************************************
	> File Name: 38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月30日 星期五 20时56分40秒
 ************************************************************************/

#include<iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define max_n 10000

int combine(int x, int i) {
    int sum = 0, h;
    for (int k = 1; k <= i; k++) {
        h = pow(10, floor(log10(k * x)) + 1);
        sum = sum * h + k * x; 
    }
    return sum;
}

int is_flag[10];

int add_num(int x, int i) {
    while (x) {
        if (is_flag[x % 10]) return 0;
        is_flag[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int digits(int x) {
    return (floor(log10(x)) + 1);
}

int is_val(int x) {
    int flag = 1, i = 1;
    memset(is_flag, 0, sizeof(is_flag));
    is_flag[0] = 1;
    int num = 0;
    while (flag && num < 9) {
        flag = flag && add_num(x, i);
        num += digits(i * x);
        i++;
    }
    if (!flag || num > 9) return 0;
    return combine(x, i);
}

int main() {
    int max = 0;
    /*for (int i = 1; i < max_n; i++) {
        if (!is_val(i)) continue;
        int p = is_val(i);
        if (p > max) max = p;
    }*/
    cout << is_val(9) << endl;
    //cout << max << endl;
    return 0;
}
