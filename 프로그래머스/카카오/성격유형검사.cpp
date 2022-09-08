#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;
map<string, pair<int, int>> mp;

string solution(vector<string> survey, vector<int> choices) {
    mp["AN"] = {0,0};
    mp["NA"] = {0,0};
    mp["CF"] = {0,0};
    mp["FC"] = {0,0};
    mp["MJ"] = {0,0};
    mp["JM"] = {0,0};
    mp["RT"] = {0,0};
    mp["TR"] = {0,0};
    string answer = "";
    for (int i = 0; i < survey.size(); ++i) {
        string s = survey[i];
        if(4-choices[i] > 0){
            mp[{s[0],s[1]}].first+=abs(4-choices[i]);
        }else if(4-choices[i] < 0){
            mp[{s[0], s[1]}].second+=abs(4-choices[i]);
        }
    }
    map<char, int> store;
    store['A'] += mp["AN"].first;
    store['A'] += mp["NA"].second;
    store['N'] += mp["NA"].first;
    store['N'] += mp["AN"].second;
    
    store['C'] += mp["CF"].first;
    store['C'] += mp["FC"].second;
    store['F'] += mp["CF"].second;
    store['F'] += mp["FC"].first;
    
    store['M'] += mp["MJ"].first;
    store['M'] += mp["JM"].second;
    store['J'] += mp["MJ"].second;
    store['J'] += mp["JM"].first;

    store['R'] += mp["RT"].first;
    store['R'] += mp["TR"].second;
    store['T'] += mp["RT"].second;
    store['T'] += mp["TR"].first;

    if (store['R'] >= store['T']) {
        answer+="R";
    }else{
        answer+="T";
    }
    if (store['C'] >= store['F']) {
        answer+="C";
    }else{
        answer+="F";
    }
    if (store['J'] >= store['M']) {
        answer+="J";
    }else{
        answer+="M";
    }
    if (store['A'] >= store['N']) {
        answer+="A";
    }else{
        answer+="N";
    }
    return answer;
}
