#include <iostream>
#include <vector>
using namespace std;

vector<int> v[500001];
int visited[500001];
int cnt = 0;

void dfs(int x, int deph) {

	if (v[x].size() == 1 && deph%2 ==1) {
		cnt++;
		return;
	}
	for (int i = 0; i < v[x].size(); ++i) {
		int nx = v[x][i];
		if (!visited[nx]) {
			visited[nx] = 1;
			
			dfs(nx, deph+1);
	
		}
	}

}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int x, y;
	for (int i = 1; i < n; ++i) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);

	}

	dfs(1,0);

	if (cnt % 2 == 0) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	

}
