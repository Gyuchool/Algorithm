//20922
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int arr[200001];
int visited[200001];
vector<int> v;
int answer;
int l, r;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	visited[arr[0]] = 1;
	l = r = 0;
	while (l <= r && r < n) {

		if (visited[arr[r]] == k+1) {
			
			if (l <= r) {
				v.push_back(answer);
				answer--;
				visited[arr[l]]--;
				l++;
			}
		}
		else {
			
			if (r < n) {
				r += 1;
				visited[arr[r]]++;
				answer++;
			}
		}
		v.push_back(answer);
	}
	
		sort(v.begin(), v.end());
		cout << v.back();

	
		
	
}
