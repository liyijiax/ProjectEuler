/*************************************************************************
	> File Name: 25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月29日 星期四 22时05分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

int fib[3][1005] = {{0, 0}, {1, 1}, {1, 1}};

int main() {
    int n = 2;
    while (fib[n % 3][0] < 1000) {
        n += 1;
        int *a = fib[n % 3], *b = fib[(n - 1) % 3], *c = fib[(n - 2) % 3];
        a[0] = b[0];
        for (int i = 1; i <= a[0]; i++) {
            a[i] = b[i] + c[i];
        }
        for (int j = 1; j <= a[0]; j++) {
            if (a[j] < 10) continue;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
            a[0] += (j == a[0]);
        }
    }
    cout << n << endl;
    return 0;
}
