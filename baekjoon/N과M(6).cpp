#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int v[10001];
int visited[10001];
int arr[10001];

void go(int cnt, int x) {
	
	if (cnt == m) {
		for (int i = 0; i < m; ++i) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = x; i < n; ++i) {
		
		if (!visited[i]) {
			visited[i] = 1;
			v[cnt] = arr[i];
			go(cnt+1,i+1); // 왼쪽보다 큰 수만 가능하도록
			visited[i] = 0;
		}
		
	}
	
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	go(0, 0);
}
