/*************************************************************************
	> File Name: 13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月02日 星期一 19时54分12秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char num[55];
int ans[55] = {0};

void add(char *num) {
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        ans[len - i] += num[i] - '0';
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (ans[0] == i);
    }
}

int main() {
    ans[0] = 1;
    for (int i = 0; i < 100; i++) {
        scanf("%s", num);
        add(num);
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        cout << ans[i];
    }
    printf("\n");
    cout << ans[0] << endl;
    return 0;
}
