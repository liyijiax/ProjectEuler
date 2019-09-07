/*************************************************************************
	> File Name: 39.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月04日 星期三 23时18分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int find(int p) {
    int cnt = 0;
    for (int i = 1; i < 32; i++) {
        for (int j = i + 1; j < 32; j++) {
            if (gcd(i, j) != 1) continue;
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = i * i + j * j;
            if (p % (a + b + c) == 0) {
                cnt++;
                int x = p / (a + b + c);
                cout << "i " << i << " " << "j " << j << endl;
                cout << x * a << " " << x * b << " " << x * c << endl;
            }
        }
    }
    return cnt;
}

int main() {
    int max = 0, p;
    cout << find(120) << endl;
    /*for (int i = 1; i <= max_n; i++) {
        int tmp = find(i);
        if (tmp > max) max = tmp, p = i;
    }*/
    cout << max << endl;
    return 0;
}
