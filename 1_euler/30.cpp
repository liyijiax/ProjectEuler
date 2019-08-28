/*************************************************************************
	> File Name: 30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月27日 星期二 20时18分56秒
 ************************************************************************/

#include<iostream>
#include <math.h>
using namespace std;
#define max_n 354294

int is_val(int x) {
    int tmp = x, sum = 0;
    while (x) {
        sum += (int)pow(x % 10, 5); // pow返回值double类型
        x /= 10;
    }
    return tmp == sum;
}
int main() {
    int sum = 0;
    for (int i = 2; i < max_n; i++) {
        if (is_val(i)) sum += i;
    }
    cout << sum << endl;
    return 0;
}
