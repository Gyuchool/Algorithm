#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<char, int> mp;
int solution(string name) {
    int answer = 0;
    int len = name.size();
    int mid = len / 2; 
    int front = 0; 
    int back = 0; int half_front = 0; int half_back = 0;

    for(int i=0; i<26; ++i){
        mp['A'+i] = i;
    }
    for(int i=0; i<name.size(); ++i){
        if(name[i]<='N'){
            answer = answer + mp[name[i]];
        }
        else{
            answer = answer + (26 - (mp[name[i]]));
        }
        if (name[i] != 'A') { 
            front = i; 
            if (i <= mid) 
                half_front = i; 
        } 
        if (name[len - i] != 'A') { 
            back = i; 
            if (len - i > mid) 
                half_back = i;
        }
    } 
    answer += min(min(front, back), min(half_back * 2 + half_front, half_front * 2 + half_back));
    
    return answer;
}
