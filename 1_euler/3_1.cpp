/*************************************************************************
	> File Name: 3_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月27日 星期二 18时17分17秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 600851475143LL

int main() {
    long long i = 2, ans = 0, num = N;
    while (i * i <= num) {
        if (num % i == 0) ans = i;
        while (num % i == 0) num /= i;
        i++;
    }
    if (num != 1) ans = num;
    cout << ans << endl;
    return 0;
}
