#include <iostream>
using namespace std;

int arr[1001];

int sum(int n, int m) {
	int k = 1;
	int index = 0;
	for (int i = 1; index <= 1000; i++) {
		for (int j = 0; j < k; j++){
			arr[index++] = k;
		}
		k++;
	}

	int sum = 0;
	for (int i = n-1; i < m; i++) {
		sum += arr[i];
	}

	return sum;
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << sum(n, m);
}
