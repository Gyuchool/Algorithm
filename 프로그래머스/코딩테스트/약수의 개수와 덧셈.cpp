#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int left, int right) {
  
    int answer = 0;
    for(int i = left; i <= right; i++) {
         int cnt=0;
        for(int j=1; j<=i; ++j){
            if(i%j==0){
                cnt++;
                cnt%=2;
            }
        }
        if(cnt){
            answer-=i;
        }
        else{
            answer+=i;
        }
    }

    return answer;
}
