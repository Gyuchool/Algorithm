//백준 20055 (7:30 ~ 
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<pair<int, bool>> belt; //가중치, 로봇 존재 여부
int answer = 0;

void circulation() {
	vector<pair<int, bool>> tmp;

	for (int i = 0; i < belt.size(); i++) {
		tmp.push_back(belt[i]);
	}
	for (int i = 1; i < belt.size(); i++) {
		belt[i] = tmp[i - 1];
	}
	
	belt[n - 1].second = false; //도착 즉시 내리기;;

	belt[0] = tmp[belt.size() - 1];
	for (int i = n; i < 2 * n; i++) {
		belt[i].second = false;
	}
}

void second() {
	
	for (int i = n - 2; i >= 0; i--) {
		if (belt[i].second == true) {
			
			if (belt[i + 1].second == false && belt[i + 1].first >= 1) {
				belt[i + 1].first--;
				belt[i + 1].second = true;
				belt[i].second = false;
			}
		}
	}
}

void third() {
	if (belt[0].first > 0) {
		belt[0].first--;
		belt[0].second = true;
	}
}

bool stop() {
	int cnt = 0;

	for (int i = 0; i < 2 * n; i++) {
		if (belt[i].first == 0) {
			
			cnt++;
		}
	}
	
	if (cnt >= k) {
		return true;
	}
	return false;
}

int main() {
	cin >> n >> k;
	int value;

	for (int i = 0; i < 2*n; i++) {
		cin >> value;
		belt.push_back({ value, false });
	}
	
	while (!stop()) {
		circulation();
		second();
		third();
		answer++;
	}
	cout << answer;
	

}
