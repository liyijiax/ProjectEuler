/*************************************************************************
	> File Name: 11.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月29日 星期四 08时48分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 20

int num[max_n + 5][max_n + 5] = {0};
int go[4][2] = {
    0, 1,
    1, 1,
    1, 0,
    1, -1
};

int calc(int x, int y) {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int p = 1; // 每一轮都要更新
        for (int step = 0; step < 4; step++) {
            int dx = x + step * go[i][0];
            int dy = y + step * go[i][1];
            if (dx < 0 || dx >= max_n) break;
            if (dy < 0 || dy >= max_n) break;
            p *= num[dx][dy];
        } 
        if (p > ans) ans = p;
    }
    return ans;
} 

int main() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j < max_n; j++) {
            cin >> num[i][j];
        }
    }
    int ans = 0, p = 0;
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j < max_n; j++) {
            p = calc(i, j);
            if (p > ans) ans = p;
        }
    }
    cout << ans << endl;
    return 0;
}
