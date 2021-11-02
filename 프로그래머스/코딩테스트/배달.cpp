#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 500000;
int answer[55]; 
vector<pair<int, int>> line[55];//<거리, 연결상대> 간선

void dijkstra(int start) {
	answer[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;//최소 힙으로 변환
		pq.pop();

		if (answer[current] < distance) {
			continue;
		}
		for (int i = 0; i < line[current].size(); ++i) {
			//선택된 노드의 인접노드 
			int next = line[current][i].second;
			int NextD = answer[current] + line[current][i].first;
			if (NextD < answer[next]) {
				answer[next] = NextD;
				pq.push(make_pair(-NextD, next));
			}
		}
	}
}
int solution(int N, vector<vector<int> > road, int K) {
   
    for (int i = 1; i <= N; ++i) {
        answer[i] = INF;
    }
	for (int i = 0; i < road.size(); i++) {
		
		line[road[i][0]].push_back({ road[i][2], road[i][1] });
        line[road[i][1]].push_back({ road[i][2], road[i][0] });
	}
    dijkstra(1);
    
	int res = 0;
    
	for (int i = 1; i <= N; i++) {
		if (answer[i] <= K) {
			res++;
		}
	}
    return res;
}
