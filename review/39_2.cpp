/*************************************************************************
	> File Name: 39_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月07日 星期六 23时04分16秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000

int cnt[max_n + 5] = {0};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void add_num(int num) {
    for (int i = num; i <= max_n; i += num) {
        cnt[i]++;
    } 
}

int main() {
    int res, max = 0;
    for (int i = 1; i < 32; i++) {
        for (int j = i + 1; j < 32; j++) {
            if (gcd(i, j) - 1) continue;
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = i * i + j * j;
            add_num(a + b + c);
        }
    }
    for (int i = 1; i <= max_n; i++) {
        if (cnt[i] > max) res = i, max = cnt[i];
    }
    cout << res << endl;
    return 0;
}
