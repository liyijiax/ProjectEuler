/*************************************************************************
	> File Name: 44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月31日 星期六 15时57分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
typedef long long int1;

int1 pentagonal(int1 x) {
    return (3 * x - 1) * x / 2;
}

int is_pentagonal(int1 x, int1 end) {
    int head = 1;
    int mid;
    while (head <= end) {
        mid = (head + end) >> 1;
        if (pentagonal(mid) == x) break;
        if (pentagonal(mid) < x) head = mid + 1;
        else end = mid - 1;
    } 
    return (pentagonal(mid) == x);
}

int main() {
    int d = INT32_MAX, i = 2;
    //cout << is_pentagonal(5, 10) << endl;
    while (pentagonal(i) - pentagonal(i - 1) < d) {
        int j = i - 1;
        while ((pentagonal(i) - pentagonal(j) < d) && j > 0) {
            int1 sum = pentagonal(i) + pentagonal(j);
            int1 sub = pentagonal(i) - pentagonal(j);
            j--;
            if (!is_pentagonal(sum, 2 * i)) continue;
            if (!is_pentagonal(sub, 2 * j)) continue;
            if (!(sub < d)) continue;
            //cout << i << " : " << j << endl;
            //cout << pentagonal(i) << " : " << pentagonal(j) << endl;
            d = sub;
            //cout << "d: " << d << endl;
        } 
        i++;
    }
    cout << d << endl;
    return 0;
}
