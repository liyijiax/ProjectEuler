/*************************************************************************
	> File Name: 2_1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月10日 星期六 10时20分35秒
 ************************************************************************/

#include<stdio.h>
#define max_n 4000000

int fib[45];

int main() {
    fib[1] = 1, fib[2] = 2;
    int n = 2;
    while (fib[n - 1] + fib[n] < max_n) {
        n++;
        fib[n] = fib[n - 1] + fib[n - 2];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (fib[i] % 2) continue; //这样写减少代码缩进
        sum += fib[i]; 
    }
    printf("%d\n", sum); //sum结果看起来可能小了，变换格式输出下看看防止错了
    return 0;
}
