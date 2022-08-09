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
---
#include <iostream>
#include <vector>

using namespace std;

vector<string> v;

int solution(string s) {
       for (int i = 1; i <= s.size() / 2+1; ++i) {
        string standard = s.substr(0, i);
        int k=0;
        int cnt = 0;
        string tmp = "";
        for (int j = 0; j < s.size(); j += i) {
            if (s.substr(j, i) == standard) {
                cnt++;
            } else {
                if (j + i >= s.size()) {
                    k=j;
                    break;
                }
                if (cnt == 1) {
                    tmp += standard;
                } else {
                    tmp += to_string(cnt) + standard;
                }
                cnt = 1;
                standard = s.substr(j, i);
            }
        }
        if (cnt == 1) {
            tmp += standard;
        } else {
            tmp += to_string(cnt) + standard;
        }
        if(k){
            tmp += s.substr(k);
        }
        v.push_back(tmp);
    }
    int min =9876543210;
    
    for(int i=0; i<v.size(); i++){
        if (min > v[i].size()) {
            min = v[i].size();
        }
    }
    return min;
}
