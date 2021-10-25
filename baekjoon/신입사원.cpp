#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100001];

int main() {
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	int t, n;
	cin >> t;

	for (int j = 0; j < t; ++j) {
		cin >> n;
		
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr, arr + n);

		int criteria = arr[0].second;
		int result = 1;
	
		for (int i = 1; i < n; ++i) {
			if (arr[i].second < criteria) {
				result++;
				criteria = arr[i].second;
			}
		}
		cout << result<<'\n';
	}
	
}
