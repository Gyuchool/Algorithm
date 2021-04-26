#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
int visited[101];
int cnt = 0;

void bfs(int x) {
	visited[x] = 1;
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int cx = q.front();
		q.pop();

		for (int i = 0; i < v[cx].size(); ++i) {

			if (!visited[v[cx][i]]) {
				visited[v[cx][i]] = 1;
				cnt++;
				q.push(v[cx][i]);
				
			}
		}
		
	}

}

int main() {
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	bfs(0);
	cout << cnt;



}
