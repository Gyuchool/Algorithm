#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int a, b;
	int x, y;
	for (int i = 0; i < t; ++i) {
		cin >> a >> b;
		for (int i = 0; i < b; ++i) {
			cin >> x >> y;
		}
		cout << a - 1 << '\n';
	}
}
