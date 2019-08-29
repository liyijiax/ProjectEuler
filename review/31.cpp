/*************************************************************************
	> File Name: 31.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月29日 星期四 22时45分09秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 8
#define max_m 200

int w[max_n] = {1, 2, 5, 10, 20, 50, 100, 200};
int res[max_m + 5] = {0};

int main() {
    res[0] = 1;
    for (int i = 0; i < max_n; i++) {
        for (int j = w[i]; j <= max_m; j++) {
            res[j] += res[j - w[i]];
        }
    }    
    cout << res[max_m] << endl;
    return 0;
}
