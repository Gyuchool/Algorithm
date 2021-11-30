#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;// location, 순위
  
    int big = 0;
    for(int i=0; i<priorities.size(); i++){
        q.push({i, priorities[i]});
    }
    sort(priorities.begin(), priorities.end());
    
    int size = priorities.size();
    int up =size;
    while(!q.empty()){
        int id = q.front().first;
        int rank = q.front().second;
        q.pop();
        if(rank<priorities[priorities.size()-1]){
            q.push({id, rank});   
        }
        else{
            answer++;
            priorities.pop_back();
            if(id == location){
                return answer;
            }
        }
    }
    return answer;
}
