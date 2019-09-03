/*************************************************************************
	> File Name: 26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月03日 星期二 21时03分15秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define max_n 1000

int reserve[1000] = {0};

int get_len(int n) {
    memset(reserve, 0, sizeof(reserve));
    int ret = 1 % n, num = 1;
    while (!reserve[ret] && ret) {
        reserve[ret] = num++;
        ret *= 10;
        ret %= n;
    }
    return num - reserve[ret];
}

int main() {
    int curlen, max_len = 0, num;
    for (int i = 1; i < max_n; i++) {
        curlen = get_len(i);
        if (curlen < max_len) continue;
        max_len = curlen;
        num = i;
    }
    cout << num << endl;
    return 0;
}
