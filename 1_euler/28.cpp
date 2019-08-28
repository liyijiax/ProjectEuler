/*************************************************************************
	> File Name: te.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月27日 星期二 19时52分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int sum = 1;
    for (int i = 3; i <= 1001; i += 2) {
        sum += 4 * i * i - 6 * i + 6;        
    }
    cout << sum << endl;
    return 0;
}
