#include <iostream>
#include <queue>
using namespace std;

int n, m;
int impo;
int answer;

int main() {
	int t;
	
	cin >> t;
	for (int j = 0; j < t; ++j) {
		cin >> n >> m;
		priority_queue<int> pq;	//중요도
		queue<pair<int, int>> q;
		answer = 0;

		for (int i = 0; i < n; ++i) {
			cin >> impo;
			pq.push(impo);
			q.push({ impo, i });
		}


		while (!q.empty()) {

			if (q.front().first != pq.top()) {
				q.push({ q.front().first, q.front().second });
				
			}
			else {
				
				pq.pop();
				answer++;
				if (q.front().second == m) {
					cout << answer << '\n';
					break;
				}
			}
			q.pop();
		}
	

	}
}
