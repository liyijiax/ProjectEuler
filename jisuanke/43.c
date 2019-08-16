/*************************************************************************
	> File Name: 43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 19时27分22秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main() {
    int n;
    scanf("%d", &n);
    int64_t num[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%"PRId64, &num[i][j]);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            num[i][j] += (num[i + 1][j] > num[i + 1][j + 1] ? num[i + 1][j] : num[i + 1][j + 1]);
        }
    }
    printf("%"PRId64, num[0][0]);
    return 0;
}
