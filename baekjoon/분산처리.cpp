#include <iostream>
#include <algorithm>
using namespace std;

int var(int a, int b) {
	int c = 1;
	for (int i = 1; i <= b; ++i) {
		c = (c*a) % 10;
		if (c == 0) {
			c = 10;
		}
	}
	
	return c;
}

int main() {
	int t;
	cin >> t;

	int a, b;
	for (int i = 0; i < t; ++i) {
		cin >> a >> b;
		cout << var(a, b) << endl;
	}

}
