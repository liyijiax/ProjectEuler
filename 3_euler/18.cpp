/*************************************************************************
	> File Name: 18_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 18时22分53秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define max_n 20

int val[max_n + 5][max_n + 5];
int tmp[max_n + 5][max_n + 5];

int dfs(int i, int j, int n) {
    if (i + 1 == n) return val[i][j];
    if (tmp[i][j]) return tmp[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    return tmp[i][j] = (val1 > val2 ? val1 : val2) + val[i][j];
}

int main() {
    for (int i = 0; i < max_n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    memset(tmp, 0, sizeof(tmp));
    cout << dfs(0, 0, max_n) << endl;
    return 0;
}
