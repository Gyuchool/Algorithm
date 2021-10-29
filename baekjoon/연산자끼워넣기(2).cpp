#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[12];
int p, minu, mul, na;
int ma=-1000000000, mi = 1000000001;
int res;

void start(int x, int plus, int minus, int mul, int na, int res) {
	if (x == n) {

		ma = max(ma, res);
		mi = min(mi, res);
		return;
	}

	if (plus) {
		start(x + 1, plus - 1, minus, mul, na, res+arr[x]);
	}
	if (minus) {
		start(x + 1, plus, minus-1, mul, na, res-arr[x]);
	}
	if (mul) {
		start(x + 1, plus, minus, mul -1, na, res*arr[x]);
	}
	if (na) {
		start(x + 1, plus, minus, mul, na - 1, res/arr[x]);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> p >> minu >> mul >> na;
	res = arr[0];

	start(1, p, minu, mul, na, res);

	cout << ma << endl << mi << endl;
}
