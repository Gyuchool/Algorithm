#include <iostream>
using namespace std;

int n, m;
int A[51][51];
int B[51][51];

void change(int i, int j) {
	for (int k = i; k < i + 3; ++k) {
		for (int x = j; x < j + 3; ++x) {
			if (A[k][x] == 1) {
				A[k][x] = 0;
			}
			else {
				A[k][x] = 1;
			}
		}
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &A[i][j]);			
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &B[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n-2; ++i) {
		for (int j = 0; j < m-2; ++j) {
			if (A[i][j] != B[i][j]) {
				change(i, j);
				cnt++;
			}
		}
	}
	int fail = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (A[i][j] != B[i][j]) {
				fail = 1;
				break;
			}
		}
		if (fail)break;
	}
	if (fail) {
		cout << -1;
	}
	else {
		cout << cnt;
	}

}
