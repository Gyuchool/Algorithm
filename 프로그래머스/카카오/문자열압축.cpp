#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000;
    string res="";
    string tmp="";
    
    for(int i=1; i<=s.size(); i++){ // 자르는 개수
        int cnt = 1; // 중복된 개수
        res="";
        tmp = s.substr(0,i);
        for(int j=i; j<s.size(); j+=i){
            if(s.substr(j, i) == tmp){
                cnt++;
            }
            else{
                if(cnt>1){
                    res+=to_string(cnt)+tmp; // 새롭게 만든 거 붙이고
                    cnt=1;
                    tmp = s.substr(j,i);
                }
                else{
                    cnt=1;
                    res+=tmp;
                    tmp = s.substr(j,i);
                }
            }
        }
        if(cnt>1){
            res+=to_string(cnt)+tmp; // 새롭게 만든 거 붙이고
        }
        else{
            res+=tmp;
        }
        
        if(answer > res.size()){
            answer = res.size();
        }
        
    }
    return answer;
}
