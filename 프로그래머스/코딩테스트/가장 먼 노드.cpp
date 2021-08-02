#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<pair<int, int>> v[20001];
int d[20001];
int INF = 1000000;
void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start,0});
    
    while(!pq.empty()){
        int cur = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();
        
        if(d[cur] < dist)continue;
        
        for(int i=0; i<v[cur].size(); ++i){
            int next = v[cur][i].first;
            int nextDist = dist + v[cur][i].second;
            
            if(nextDist < d[next]){
                d[next] = nextDist;
                pq.push({next, -nextDist});
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0;i<=n;++i){
        d[i]=INF;
    }
    
    for(int i=0;i<edge.size(); ++i){
        v[edge[i][0]].push_back({edge[i][1],1});        
        v[edge[i][1]].push_back({edge[i][0],1});
    }
    dijkstra(1);
    int top = -1;
    for(int i=1;i<=n; ++i){
        top = top > d[i]? top:d[i];
    }

    for(int i=0;i<=n;++i){
        if(top == d[i]){
            answer++;
        }
    }
    return answer;
}
