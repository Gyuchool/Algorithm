#include <iostream>
#include <vector>

using namespace std;

int Max(int a, int b) {
	if (a > b)return a;
	else return b;
}
int main() {
	int n;
	
	cin >> n;
	int** max = new int* [n];
	for (int i = 0; i < n; i++) {
		max[i] = new int[n];

	}
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> arr[i][j];
			
		}
	}

	max[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			if (j == 0) {
				max[i][j] = arr[i][j] + max[i-1][j];
			}
			else if (j == i) {
				max[i][j] = arr[i][j] + max[i - 1][j-1];
			}
			else {
				max[i][j] = Max(max[i - 1][j], max[i - 1][j - 1]) + arr[i][j];
			}
		}
	
	}
	int big = max[n - 1][0];
	for (int i = 0; i < n; i++) {
		if (big < max[n - 1][i])big = max[n - 1][i];
	}
	cout << big;

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	for (int i = 0; i < n; i++) {
		delete[] max[i];
	}
	delete[] max;
}
