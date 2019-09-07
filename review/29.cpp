/*************************************************************************
	> File Name: 29.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月04日 星期三 22时17分49秒
 ************************************************************************/

#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#define max_n 10000
#define max_m 210

int* res[max_n] = {0};
int res_len = 0;

int find(int *temp) {
    for (int i = 0; i < res_len; i++) {
        if (memcmp(res[i], temp,  max_m * sizeof(int))) continue;
        // 返回是地址差
        return i + 1; // bug 如果写i，那么0下标可能返回0
    }
    return 0;
}

int *calc(int a, int b) {
    int *temp = (int *)calloc(sizeof(int), max_m);
    temp[0] = 1, temp[1] = 1;
    for (int j = 0; j < b; j++) {
        for (int i = 1; i <= temp[0]; i++) {
            temp[i] *= a;
        }
        for (int i = 1; i <= temp[0]; i++) {
            if (temp[i] < 10) continue;
            temp[i + 1] += temp[i] / 10;
            temp[i] %= 10;
            temp[0] += (temp[0] == i);
        }
    }
    return temp;
}

int main() {
    memset(res, 0, sizeof(res));
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int *temp = calc(a, b);
            if (find(temp) == 0) {
                res[res_len++] = temp;
            } else {
                free(temp);
            }
        }
    }
    cout << res_len << endl;
    return 0;
}
