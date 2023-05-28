#include <string>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long solution(int r1, int r2) {
    
    long long answer = 0;
    answer=(long long)(r2-r1+1)*4;
    for(long long x = 1; x<=r1; ++x){
        long long a = sqrt((long long)r2*r2 - x*x);
        long long b = ceil(sqrt((long long)r1*r1 - (long long)x*x));
        if(b != 0){
            answer+=(a-b+1)*4;
        }
        else{
            answer+=(a-b)*4;
        }
    }
    
    for(long long x = r1+1; x<r2; ++x){
        long long a = sqrt((long long)r2*r2 - (long long)x*x);
        answer+=4*(a);
    }
    return answer;
}
