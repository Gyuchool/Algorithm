#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s;
    while(n!=0){
        s+=(n%3)+'0';
        n/=3;
    }
    for(int i=s.size()-1; i>=0; --i){
        if(s[i]-'0' !=0){
            answer+=(s[i]-'0')*pow(3,(s.size()-(i+1)));
        }
    }
    return answer;
}
