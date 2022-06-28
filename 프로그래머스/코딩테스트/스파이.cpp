#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

map<string, int> mp;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    for(int i=0; i<clothes.size(); i++)
    {
        string name = clothes[i][0];
        string type = clothes[i][1];
        if(mp.find(type)!=mp.end())
        {
            mp[type]= mp[type]+1;
        }
        else
        {
            mp.insert({ type, 1 });
        }
    }

    for(auto iter : mp)
    {
        answer *= (iter.second + 1);
        cout<<iter.second<<' ';
    }


    return answer - 1;
}
