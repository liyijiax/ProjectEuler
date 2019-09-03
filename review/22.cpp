/*************************************************************************
	> File Name: 22.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月03日 星期二 19时29分28秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include "22.h"
using namespace std;

int main() {
    long long i = 0, len, sum, total = 0;
    while (nameList[i++].length() != 0);
    sort(nameList, nameList + i - 1);
    i = 0;
    while (nameList[i].length() != 0) {
        sum = 0;
        for (int j = 0; j < nameList[i].length(); j++) {
            sum += nameList[i][j] - 'A' + 1;
        }
        total += sum * (++i);
    }
    cout << total << endl;
    return 0;
}
