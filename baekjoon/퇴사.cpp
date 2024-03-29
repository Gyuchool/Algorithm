#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int visited[1001];
vector<pair<int, int>> works;
int answer;
int pays;

void start(int x, int pre) {
	if (x == n) {
		answer = max(answer, pays);
		return;
	}
	if (x > n) {
		answer = max(answer, pays - works[pre].second);
		return;
	}

	for (int i = x; i < n; i++) {
		pays += works[i].second;
		start(i + works[i].first, i);
		pays -= works[i].second;
	}
}
int main() {
	cin >> n;
	int time, pay;

	for (int i = 0; i < n; i++) {
		cin >> time >> pay;
		works.push_back({ time, pay });
	}

	start(0,0);
	cout << answer;
}
