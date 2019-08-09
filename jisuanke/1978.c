/*************************************************************************
	> File Name: 1978.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 21时50分51秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100

char val[max_n + 5];
int num[max_n + 5] = {0};

void char_to_int(char *val, int *num) {
    int len = strlen(val);
    for (int i = 0; i < len - 1; i++) {
        num[len - 1 - i] = val[i] - '0';
    }
}

void sub(int *num, int x) {
    
} 

int is_val(char *val, int *num) {
    char_to_int(val, num);
    int pro = char[len - 1] - '0';
    sub(num, pro * 5);

}

int main() {
    scanf("%s", val);
    if (is_val(val, num)) printf("YES");
    else printf("NO");
    return 0;
}
