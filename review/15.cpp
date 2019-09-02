/*************************************************************************
	> File Name: 15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月02日 星期一 20时17分00秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    long long ans = 1, i = 21, j = 1;
    while (j <= 20) {
        if (i <= 40) ans *= i++;
        if (ans % j == 0) ans /= j++;
        cout << ans << ":" << i << ":" << j << endl;
    }
    cout << ans << endl;
    return 0;
}
