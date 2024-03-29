/*************************************************************************
	> File Name: 29.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 16时26分28秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define max_n 10000
#define max_m 210

int result[max_n][max_m];
int result_len = 0;

int find_result(int *num) {
    for (int i = 0; i < result_len; i++) {
        if (memcmp(result[i], num, sizeof(int) * max_m)) continue;
        return i + 1;
    }
    return 0;
}
int *calc(int a, int b) {
    int *temp = (int *)calloc(sizeof(int), max_m); // 直接定义时清空
     temp[0] = 1, temp[1] = 1;
     for (int i = 0; i < b; i++) {
            for (int j = 1; j <= temp[0]; j++) temp[i] *= a;
            for (int j = 1; j <= temp[0]; j++) {
                if (temp[j] < 10) continue;
                temp[j + 1] += temp[j] / 10;
                temp[j] %= 10;
                temp[0] += (temp[0] == j);
            }

            
    }
    return temp;
}

int main() {
    memset(result, 0, sizeof(result));
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int temp[max_m] = {0};
            int *temp;
            temp = calc(a, b);
            if (find_result(temp) == 0) {
                result[result_len++] = temp;
            }
        }
    }
    cout << result_len << endl;
    return 0;
}
