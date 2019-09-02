/*************************************************************************
	> File Name: 16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月02日 星期一 20时35分58秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 400

int ans[max_n + 5] = {0}; 

int main() {
    ans[0] = 1, ans[1] = 1;
    for (int i = 0; i < 100; i++) {
        for (int i = 1; i <= ans[0]; i++) {
            ans[i] *= 1024;
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }   
    int sum = 0;
    for (int i = 1; i <= ans[0]; i++) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}
