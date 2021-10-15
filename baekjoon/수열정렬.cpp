#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int arr[51];
int visited[51];

int main() {
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
	}
	int x = 0;
	vector<int> ans;
	sort(arr, arr + n);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[j] && v[i] == arr[j]) {
				visited[j] = 1;
				cout << j << ' ';
				break;
			}
		}
	}
	
}
