#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> mp;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    int who = 1;
    int turn = 1;
    bool sucess = false;
    mp.insert({words[0], 1});

    for (int i=1;i<words.size(); i++) {
        who = (i%n) + 1;
        turn = (i/n) + 1;
        if (words[i-1][words[i-1].size() - 1] != words[i][0]) {
            answer.push_back(who);
            answer.push_back(turn);
            sucess = true;
            break;
        }
        else{
            if (mp[words[i]] != 1) {
                mp.insert({words[i], mp[words[i]]++});
            }else{
                answer.push_back(who);
                answer.push_back(turn);
                sucess = true;
                break;
            }
        }
    }
    if (!sucess) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
