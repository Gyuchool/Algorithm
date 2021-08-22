#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<string> cache;
bool find(string name){
    for(int i=0;i<cache.size(); ++i){
        if(cache[i] == name){
            return true;
        }
    }
    return false;
}

int solution(int cacheSize, vector<string> cities) {

    int answer = 0;
    
    for(int i=0;i<cities.size(); ++i){
        
        for(int j=0;j<cities[i].size(); ++j){
            cities[i][j] = tolower(cities[i][j]);
        }
        
        if(!find(cities[i])){
            if(cache.size() < cacheSize){
                cache.push_back(cities[i]);
            }
            else{
                if(!cache.empty()){
                    cache.erase(cache.begin());
                    cache.push_back(cities[i]);
                    
                }
            }
            answer+=5;
            
        }
        else{
            for(int k=0;k<cache.size(); ++k){
                if(cache[k] == cities[i]){
                    cache.erase(cache.begin()+k);
                    cache.push_back(cities[i]);
                    break;
                }
            }
            answer++;
        }
        
    }
    return answer;
}
