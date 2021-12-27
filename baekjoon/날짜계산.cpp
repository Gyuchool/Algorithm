#include <iostream>

using namespace std;
int e=0, s=0, m=0;
int ae, as, am;

int main() {
	int answer = 0;
	cin >> ae >> as >> am;
	while (true) {
		e++; s++; m++;
		if (e > 15) {
			e = 1;
		}
		if (s > 28) {
			s = 1;
		}
		if (m > 19) {
			m = 1;
		}
		answer++;
		if (ae == e && as == s && am == m) {
			break;
		}
	}
	cout << answer;
}
