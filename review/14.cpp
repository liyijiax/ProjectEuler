/*************************************************************************
	> File Name: 14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月29日 星期四 09时30分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

int remember[max_n + 5] = {0};

long long calc(long long x) {
    int p = 0;
    if (x == 1) return 1;
    if (x < max_n && remember[x]) return remember[x]; // 注意可能越界
    if (x & 1) p = calc(x * 3 + 1) + 1;
    else p = calc(x >> 1) + 1;
    if (x < max_n) remember[x] = p;
    return p;
}

int main() {
    int ans = 0, p = 0, num = 0;
    for (int i = 1; i < max_n; i++) {
        p = calc(i);
        if (p > ans) ans = p, num = i;
    }
    cout << num << endl;
    return 0;
}
