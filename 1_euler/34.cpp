/*************************************************************************
	> File Name: 34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月27日 星期二 20时34分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 2540160 

int num[10];

void init() {
    num[0] = 1;
    for (int i = 1; i < 10; i++) {
        num[i] = i * num[i - 1];
    }
}

int is_val(int x) {
    int sum = 0, tmp = x;
    while (x) {
        sum += num[x % 10];
        x /= 10;
    }
    return sum == tmp;
}

int main() {
    int sum = 0;
    init();
    for (int i = 3; i < max_n; i++) {
        if (is_val(i)) sum += i;
    }
    cout << sum << endl;
    return 0;
}
