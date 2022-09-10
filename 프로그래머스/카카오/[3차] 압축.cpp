#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

queue<char> q;
map<string, int> mp;

vector<int> solution(string msg) {
    vector<int> answer;
    for (int i = 0; i < 26; ++i) {
        char x = 'A' + i;
        string s(1,x);
        mp[s] = i+1;
    }

    for (char ch : msg) {
        q.push(ch);
    }

    int index = 27;
    string tmp="";
    while (!q.empty()) {
        char ch = q.front();
        if (mp[tmp+ch]) {//사전에 있다면
            tmp+=ch;
            q.pop();
            if (q.empty()) {
                answer.push_back(mp[tmp]);
            }
            continue;
        }else{
            mp[tmp+ch] = index++;
            answer.push_back(mp[tmp]);
            tmp="";
        }
    }
    return answer;
}
