#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[501];    

bool compare(const pair<double, int> &a, const pair<double, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, int>> v;
    vector<pair<double, int>> v2;
    for(int i=0;i<=501; ++i){
        if(i!=0 && i<=N)
            arr[i]=0;
        else
            arr[i]=-1;
    }

    double size = stages.size();
    
    
    for(int i=0; i<size; ++i){
        if(stages[i] <=N)
            arr[stages[i]]++;
    }
    for(int i=0; i<501; ++i){
        if(arr[i] != -1){
            v.push_back({i,arr[i]});          
        }
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ++i){
        double tmp = (double)v[i].second;
        double hp = tmp/size;
        if(size<=0){
            v2.push_back({0,v[i].first});
        }else
        v2.push_back({hp, v[i].first});
        size-=tmp;
        
    }
    sort(v2.begin(), v2.end(), compare);
    for(int i=0;i<v2.size(); ++i){
    
        answer.push_back(v2[i].second);
    }
    return answer;
}
