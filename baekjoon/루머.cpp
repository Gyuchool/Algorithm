#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[200000];
int rumor[200000] = { -1, };

int n;

int count_rumor(int x) {
	int cnt = 0;
	
	for (int i = 0; i < v[x].size(); ++i) {
		if (rumor[v[x][i]] != -1) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	queue<int> q;
	queue<int> tq;
	for (int i = 0; i < 200000; ++i)rumor[i] = -1;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		while (x != 0) {
			v[i].push_back(x-1);
		
			cin >> x;
		}
	}
	int diffusers;
	cin >> diffusers;

	for (int i = 0; i < diffusers; ++i) {
		int k;
		cin >> k;
		rumor[k-1] = 0;
		q.push(k-1);
	}
	int current = 0;
	while (!q.empty()) { // 주변에 루머 개수 카운트 하고 자기 size랑 비교하기

		int cx = q.front();
		q.pop();

		for (int i = 0; i < v[cx].size(); ++i) {
			int nx = v[cx][i]; // 주변
			if (rumor[nx] != -1)continue;

			int rumors = count_rumor(nx);	//cnt

			if ((v[nx].size()+1) / 2 > rumors)continue;
			tq.push(nx);
		}
		// 연결된거 모든것을 확인했으므로 1일을 더해준다.
		if (q.empty()) {
			current++;
			//루머를 믿는 사람들의 날짜를 입력해주고  q에도 넣어준다.
			while (!tq.empty()) {
				int ntx = tq.front();
				tq.pop();
				rumor[ntx] = current;
				q.push(ntx);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << rumor[i] << " ";
	}
}

