/*************************************************************************
	> File Name: 24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月03日 星期二 20时19分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

int val[10] = {0};
int dnum[10] = {0};

void init() {
    val[0] = 1, dnum[0] = 1;
    for (int i = 1; i <= 9; i++) {
        val[i] = val[i - 1] * i;
        dnum[i] = 1;
    }
    return ;
}

int get_num(int n, int k) {
    int p = k / val[n] + 1, j = -1, i = 0;
    while (i < p) {
        i += dnum[++j];
    }
    dnum[j] = 0;
    return j;
}

int main() {
    int k;
    init();
    cin >> k;
    k--;
    for (int i = 9; i > 0; i--) {
        int num = get_num(i, k);
        k %= val[i];
        cout << num;
    }
    cout << endl;
    return 0;
}
