/*************************************************************************
	> File Name: 1978.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 21时50分51秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define max_n 100

char val[max_n + 5];
int num[max_n + 5] = {0};

void char_to_int(char *val, int *num) {
    int len = strlen(val);
    for (int i = 0; i < len - 1; i++) {
        num[len - 1 - i] = val[i] - '0';
    }
    num[0] = len - 1;
}

void sub(int *num, int x) {
    
    for (int i = 1; i <= num[0]; i++) {
        num[i] -= x % 10;
        x /= 10;
    } 
    for (int i = 1; i <= num[0]; i++) {
        if (num[i] >=  0) continue;
        num[i + 1]--;
        num[i] += 10;
    }
    for (int i = num[0]; i > 0; i--) {
        if (num[i] >  0) break;
        num[0]--;
    }
} 

int is_17(int *num) {
    while(!(num[0] < 2 && ((num[2] * 10 + num[1]) < 17 ))) {
        sub(num, 17);
    }
    int remain = num[2] * 10 + num[1];
    return !remain;
}

int is_val(char *val, int *num) {
    int len = strlen(val);
    char_to_int(val, num);
    int pro = val[len - 1] - '0';
    for (int i = 0; i <= num[0]; i++) {
        printf("%d", num[i]);
    }
    printf("\n");
    printf("%d\n", pro);
    int x = pro * 5;
    //出现num位数小于等于要减去的5的倍数
    int digit = floor(log10(x)) + 1;
    if (digit >= num[0]) {
        int sum = 0;
        int h = 1;
        for(int i = 1; i <= num[0]; i++) {
            sum += num[i] * h;
            h *= 10;
        }
        return !((sum - x) % 17);
    }
    //num位数多余5的相应倍数
    sub(num, x);
    for (int i = 0; i <= num[0]; i++) {
        printf("%d", num[i]);
    }
    printf("\n");
    //判断余下的数是否是17倍数
    return is_17(num);
}

int main() {
    scanf("%s", val);
    printf("%s\n", val);
    if (is_val(val, num)) printf("YES");
    else printf("NO");
    return 0;
}
