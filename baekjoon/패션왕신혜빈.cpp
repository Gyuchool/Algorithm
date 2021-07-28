#include <iostream>
#include <vector>

using namespace std;


int main() {
	int n, m;
	string type, name;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		long long answer = 0;
		cin >> m;
		answer = m;
		vector<pair<string, int>> v;

		for (int j = 0; j < m; ++j) {
			cin >> name >> type;
			int flag = 0;

			for (int k = 0; k < v.size(); ++k) {
				if (v[k].first == type) {
					flag = 1;
					v[k].second++;
					break;
				}
			}
			if (flag == 0) {
				v.push_back({ type, 1 });
			}
		}
		long long sum = 1;
		
		for (int j = 0; j < v.size(); ++j) {
			sum *= (v[j].second + 1);
		}

		answer = sum - 1;
		cout << answer << endl;
	}
}
