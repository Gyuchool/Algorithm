#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k;
	cin >> k;
	int a;
	int sum = 0;
	stack<int> st;
	for (int i = 0; i < k; ++i) {
		cin >> a;
		if (a == 0)
			st.pop();
		else
			st.push(a);
	}
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;

}
