#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visited[20001];
int check[20001];
vector<int> vec[20001];
int v, e;

bool isBipartiteGraph() {
	for (int i = 0; i < v; i++) {
		int gsize = vec[i].size();
		visited[i]=1;
		for (int j = 0; j < gsize; j++) {
			int next = vec[i][j];

			if (check[i] == check[next]) {
				return false;
			}
		}
	}
	return true;
}
void init(int v) {
	for (int i = 0; i < v; ++i) {
		visited[i] = 0;
		check[i] = 0;
		vec[i].clear();
	}
}
void bfs(int start) {
	queue<int> q;
	q.push(start);
	if (!check[start] && !visited[start]) {
		visited[start] = 1;
		check[start] = 1;
	}
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int color;
		if (check[x] == 1) {
			color = 2;
		}
		else if (check[x] == 2) {
			color = 1;
		}

		for (int i = 0; i < vec[x].size(); ++i) {
			int y = vec[x][i];
			
			if (!visited[y]) {
				visited[y] = 1;
				check[y] = color;
				q.push(y);
				
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {

		cin >> v >> e;
		
		for (int j = 0; j < e; ++j) {
			int x, y;
			cin >> x >> y;
			vec[x-1].push_back(y-1);
			vec[y-1].push_back(x-1);
		}

		for (int i = 0; i < v; ++i) {
			if (!visited[i] && !check[i]) {
				bfs(i);
			}
		}
		if (isBipartiteGraph()) {
			cout << "YES"<<'\n';
		}
		else {
			cout << "NO"<<'\n';
		}
		init(v);
	}

	
}
