#include <iostream>
#include <algorithm>
using namespace std;

int v[10001];
int n, m;
int arr[10001];

void go(int cnt) {

	if (cnt == m) {
		for (int i = 0; i < m; ++i) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i) {
		
			v[cnt] = arr[i];
			go(cnt + 1);
		
	}

}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	go(0);

}
