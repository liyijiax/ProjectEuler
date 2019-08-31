/*************************************************************************
	> File Name: 45.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月31日 星期六 17时05分34秒
 ************************************************************************/

#include<iostream>
using namespace std;
typedef long long int1;

int1 hexagonal(int1 x) {
    return (2 * x - 1) * x;
}

int1 pentagonal(int1 x) {
    return x * (3 * x - 1) / 2;
}

int1 is_val(int1 x, int1 (*f)(int1)) {
    int head = 1, end = x, mid;
    while (head <= end) {
        mid = (head + end) >> 1;
        if (f(mid) == x) return 1;
        if (f(mid) < x) head = mid + 1;
        else end = mid - 1;
    }
    return 0;
}

int main() {
    int n = 144;
    while (!is_val(hexagonal(n), pentagonal)) {
        n++;
    }
    cout << hexagonal(n) << endl;
    return 0;
}
