#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;
vector<long long> v;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	long long a;
	long long x, y;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	int r = v.size() - 1;
	int l = 0;
	long long min = abs(v[l] + v[r]);
	x = v[l];
	y = v[r];
	while (l<r)
	{
		if (abs(v[l] + v[r]) < min) {
			min = abs(v[l] + v[r]);
			x = v[l];
			y = v[r];
		}
		else {
			if (v[r] + v[l] > 0) {
				r--;
			}
			else if (v[r] + v[l] == 0) {
				x = v[l];
				y = v[r];
				break;
			}
			else {
				l++;
			}
		}
	}
	cout << x << ' ' << y;

}
