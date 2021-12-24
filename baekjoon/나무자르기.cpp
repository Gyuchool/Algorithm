#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long arr[1000001];
vector<long long> v;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long sum=0;

	long long max = arr[n - 1];
	long long bottom = 0;
	vector<int> answer;

	while (bottom <= max) {
		
		sum = 0;
		long long mid = (max + bottom) / 2;

		for (int i = 0; i < n; ++i) {
			if (arr[i] > mid) {
				sum = sum + (arr[i] - mid);
			}

		}
		if (sum == m) {
			answer.push_back(mid);
			break;
		}
		else if (sum > m) {
			v.push_back(mid);
			bottom = mid + 1;
		}
		else {
			if (sum < m) {
				max = mid - 1;
			}
		}
	}
	if (!answer.empty()) {
		cout << answer[0];
	}
	else if (!v.empty()) {
		sort(v.begin(), v.end());
		cout << v[v.size() - 1];
	}
	
}
