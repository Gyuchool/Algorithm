#include <iostream>
using namespace std;

int main() {
	int n,x;
	cin >> n;
	int sum2 = 0;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		sum2 += x / 2;
		sum += x;

	}
	
	if (sum % 3 == 0) { //가능성 ㅇ
		if (sum2 >= sum / 3) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
	
}
