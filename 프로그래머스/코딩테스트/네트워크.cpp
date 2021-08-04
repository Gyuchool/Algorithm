#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[201];
queue<int> q;
vector<int> v[201];

void bfs(int x, int n){
    visited[x]=1;
    q.push(x);
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        for(int i=0; i<v[cx].size(); ++i){
            int nx = v[cx][i];
    
            if(!visited[nx]){
                visited[nx]=1;
                q.push(nx);
            }
        }
        
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size(); ++i){
        for(int j=0;j<computers[i].size(); ++j){
            if(computers[i][j]){
                v[i].push_back(j);
                v[j].push_back(i);            
            }
        }
    }
    
    for(int i=0;i<computers.size(); ++i){
        for(int j=0;j<computers[i].size(); ++j){
            if(!visited[i] && computers[i][j]){
                bfs(i,n);
                answer++;
            }
        }
    }
    
    
    return answer;
}
