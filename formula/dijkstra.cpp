#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int answer[20001];//최소 비용
vector<pair<int, int>> line[300001];//<거리, 연결상대> 간선
int INF = 2000010;

void dijstra(int start) {
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

int main() {

	int x, e;
	cin >> x >> e;//x 정점의 갯수 e 간선의 갯수
	int a, b, c;
	int k;
	cin >> k;//시작 점
	for (int i = 1; i <= x; ++i) {
		answer[i] = INF;
	}
	
	for (int i = 1; i <= e; ++i) {
		cin >> a >> b >> c;
		line[a].push_back({c, b});
		//line[b].push_back({c,a});
	}

	dijstra(k);
	//answer[]에 k부터의 거리들 저장됨
	
	for (int i = 1; i <= x; ++i) {
		if (answer[i] != INF) {
			cout << answer[i] << endl;
		}
		else {
			cout << "INF" << endl;
		}
	}

	return 0;
}
