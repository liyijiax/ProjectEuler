/*************************************************************************
	> File Name: 36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月27日 星期二 20时58分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int is_val(int x, int base) {
    int tmp = x, sum = 0;
    while (x) {
       sum = x % base + sum * base;
        x /= base;
    }
    return sum == tmp;
}
int main() {
    int sum = 0;
    for (int i = 1; i < max_n; i++) {
        if (is_val(i, 2) && is_val(i, 10)) sum += i;
    } 
    cout << sum << endl;
    return 0;
}
