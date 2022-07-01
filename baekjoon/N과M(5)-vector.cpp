#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int>v;
int visited[10001];
int arr[10001];

void go() {

	if (v.size() == m) {
		for (int i = 0; i < m; ++i) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {

		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(arr[i]);
			go();
			v.pop_back();
			visited[i] = 0;
		}

	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	go();
}
