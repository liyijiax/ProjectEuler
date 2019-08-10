/*************************************************************************
	> File Name: 1_1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月10日 星期六 10时00分56秒
 ************************************************************************/

#include<stdio.h>

int is_val(int x) {
    if (x % 3 == 0 || x % 5 == 0) return 1;
    return 0;
}

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
