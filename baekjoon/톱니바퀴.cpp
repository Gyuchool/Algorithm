#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int tobni[4][3][3];
vector<int> v;

void rotation(int n, int dir) {
	if (dir == -1) {
		int tmp = tobni[n][0][0];

		for (int i = 1; i < 3; i++) {
			tobni[n][0][i - 1] = tobni[n][0][i];
		}
		for (int i = 1; i < 3; i++) {
			tobni[n][i - 1][2] = tobni[n][i][2];
		}
		for (int i = 2; i > 0; i--) {
			tobni[n][2][i] = tobni[n][2][i - 1];
		}
		tobni[n][2][0] = tobni[n][1][0];
		tobni[n][1][0] = tmp;
	}
	else {
		int tmp = tobni[n][0][2];
		for (int i = 2; i > 0; i--) {
			tobni[n][0][i] = tobni[n][0][i - 1];
		}
		for (int i = 1; i < 3; i++) {
			tobni[n][i - 1][0] = tobni[n][i][0];
		}
		for (int i = 1; i < 3; i++) {
			tobni[n][2][i - 1] = tobni[n][2][i];
		}
		tobni[n][2][2] = tobni[n][1][2];
		tobni[n][1][2] = tmp;
	}

}


int main() {

	for (int k = 0; k < 4; k++) {
		for (int i = 1; i < 3; i++) {
			scanf("%1d", &tobni[k][0][i]);
		}
		for (int i = 1; i <= 2; i++) {
			scanf("%1d", &tobni[k][i][2]);
		}
		for (int i = 1; i >= 0; i--) {
			scanf("%1d", &tobni[k][2][i]);
		}
		for (int i = 1; i >= 0; i--) {
			scanf("%1d", &tobni[k][i][0]);
		}
	}

	int t;
	cin >> t;
	int n, dir;
	for (int i = 0; i < t; i++) {
		cin >> n >> dir;
		int idx = n - 1;
		int l = tobni[idx][1][0];
		int r = tobni[idx][1][2];
		if (idx == 0) {
			for (int t = 0; t < 3; t++) {
				if (tobni[t][1][2] == tobni[t + 1][1][0]) {
					break;
				}
				else {
					v.push_back(t + 1);
				}
			}
			rotation(idx, dir);
			for (int i = 0; i < v.size(); i++) {
				dir = -dir;
				rotation(v[i], dir);
			}

		}
		else if (idx == 3) {
			for (int t = 3; t > 0; t--) {
				if (tobni[t][1][0] == tobni[t - 1][1][2]) {
					break;
				}
				else {
					v.push_back(t - 1);
				}
			}
			rotation(idx, dir);
			for (int i = 0; i < v.size(); i++) {
				dir = -dir;
				rotation(v[i], dir);
			}
		}
		else if (idx == 1) {
			if (l != tobni[idx - 1][1][2]) {
				rotation(idx - 1, -dir);
			}
			if (r != tobni[idx + 1][1][0]) {
				v.push_back(idx + 1);
				if (tobni[idx + 1][1][2] != tobni[idx + 2][1][0]) {
					v.push_back(idx + 2);
				}
			}
			rotation(idx, dir);
			for (int i = 0; i < v.size(); i++) {
				dir = -dir;
				rotation(v[i], dir);
			}
		}
		else {
			if (r != tobni[idx + 1][1][0]) {
				rotation(idx + 1, -dir);
			}
			if (l != tobni[idx - 1][1][2]) {
				v.push_back(idx - 1);
				if (tobni[idx - 1][1][0] != tobni[idx - 2][1][2]) {
					v.push_back(idx - 2);
				}
			}
			rotation(idx, dir);
			for (int i = 0; i < v.size(); i++) {
				dir = -dir;
				rotation(v[i], dir);
			}
		}
		v.clear();
	}

	int sum = 0;
	sum += tobni[0][0][1];
	sum += (tobni[1][0][1] * 2);
	sum += (tobni[2][0][1] * 4);
	sum += (tobni[3][0][1] * 8);

	cout << sum;
}
