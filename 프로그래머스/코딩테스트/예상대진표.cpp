#include <iostream>
#include <math.h>

using namespace std;

int go(long long n, int a, int b){
    if ((a <= (n / 2) && b > (n / 2)) || ((b <= n / 2) && (a > n / 2))) {
        return log2(n);
    } else if(a> n/2 && b > n/2){
        return go(n / 2, a - n / 2, b - n / 2);
    }
    return go(n / 2, a, b);
}
int solution(int n, int a, int b) {
    return go(n,a,b);
}
