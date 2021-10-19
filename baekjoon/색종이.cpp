#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101];
vector<pair<int, int>> v;

int main() {
	int n;
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++) {
				arr[i][j] = 1;
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
	}
	cout << cnt;
}
