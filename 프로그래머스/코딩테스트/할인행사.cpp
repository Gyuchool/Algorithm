#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, int> init(vector<string> want, vector<int> number){
    map<string, int> mp;
    for(int i=0; i<want.size(); ++i){
        mp[want[i]]=number[i];
    }
    return mp; 
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int sum = 0;
    map<string, int> result = init(want, number);
    for (int i = 0; i < number.size(); i++)
    {
        sum+=number[i];
    }
    int idx = sum -1;
    map<string, int> mp;

    for(int i=0; i<sum; ++i){
        mp[discount[i]]++;
    }
    bool isFail = false;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(mp[it->first] != result[it->first]){
            isFail = true;
        }
    }
    if(!isFail){
        answer++;
    }

    int s = 0;
    for(int i=sum; i<discount.size(); ++i){
        mp[discount[s]]--;
        mp[discount[i]]++;
        ++s;
        bool isFail = false;

        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(mp[it->first] != result[it->first]){
                isFail = true;
            }
        }
        if(!isFail){
            answer++;
        }
    }
    return answer;
}
