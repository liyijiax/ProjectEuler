/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 17时54分02秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>

int main() {
    double x;
    int fac = 1;
    for (int i = 1; i < 10; i++) {
        fac *= i;
    }
    printf("%d\n", fac);
    return 0;
}
