#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int arr[9];
int visited[10001];
int n, m;
vector<int> v;

set<vector<int>> check;


void go(int cnt) {
	if (cnt == m) {
		
		check.insert(v);
		
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(arr[i]);
			go(cnt + 1);
			v.pop_back();
			visited[i] = 0;

		}
	}
	
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	go(0);

	for (auto it = check.begin(); it != check.end(); ++it) {
		v = *it;
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}

}
