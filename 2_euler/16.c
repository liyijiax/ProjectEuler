/*************************************************************************
	> File Name: 16.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 16时05分18秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000

int ans[max_n] = {0};

int main() {
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 0; i < max_n; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= 2;
        }
        for (int k = 1; k <= ans[0]; k++) {
            if (ans[k] < 10) continue;
            ans[k] %= 10;
            ans[k + 1] += 1;
            ans[0] += (ans[0] == k);
        }
    }
    int sum = 0;
    for(int i = ans[0]; i > 0; i--) {
        sum += ans[i];
    }
    printf("%d\n", sum);
    return 0;
}
