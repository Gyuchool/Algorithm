#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
int arr[8];
int visited[8];
vector<int> v;
set<vector<int>> st;

void start(int depth) {
	if (m == v.size()) {

		if (st.find(v) != st.end()) { //찾으면
			return;
		}
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] > v[i + 1])
				return;
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout<<'\n';
		st.insert(v);
		return;
	}

	for (int i = depth; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(arr[i]);
			start(depth + 1);
			v.pop_back();
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	start(0);
}
