#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair< string,pair<string, int>>> v;
bool compare(const pair<string, pair<string, int>>& a,const pair<string, pair<string, int>>& b){
    if(a.second.first == b.second.first){
        return a.second.second < b.second.second;
    }
    return a.second.first < b.second.first;
}
string head;
string number;
int check;
vector<string> solution(vector<string> files) {
    vector<string> answer;
    int cut=0;
    for(int i=0;i<files.size(); ++i){
        check=0;
        head="";
        number="";
        for(int j=0;j<files[i].size(); ++j){
            if(check == 0 && files[i][j]>='0' && files[i][j]<='9'){
                //head자르기
                head = files[i].substr(0,j);
                check=1;cut=j;
                continue;
            }
            if(check==1 && (files[i][j]<'0' || files[i][j]>'9')){
                number = files[i].substr(cut,j-cut);
                check=2;
                break;
            }
        }
        
        if(check != 2){
            number = files[i].substr(cut);
        }
        
        for(int k=0;k<head.size(); ++k){
            head[k]=tolower(head[k]);
        }
        int num = stoi(number);
        v.push_back({files[i],{head, num}});
        
    }
    stable_sort(v.begin(), v.end(), compare);
    for(int k=0;k<v.size();++k){
            answer.push_back(v[k].first);
    }
    return answer;
}
