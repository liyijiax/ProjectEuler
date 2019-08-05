/*************************************************************************
	> File Name: e_1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 16时02分09秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#define max_n 10000

int temp[max_n];
int main() {
    int flag = 0;
    int m;
    memset(temp, 0, sizeof(temp));
    for (int i = 2; i < max_n; i++){
        if (temp[i] == 0) {
            temp[i] = i;
            for (int j = 2; i * j <= max_n; j++) {
                if(!temp[i * j]) temp[i * j] = i;
            }
        }
    }
    while (scanf("%d", &m) != EOF) {
        printf("%d\n", temp[m]);
    } 
    return 0;
}
