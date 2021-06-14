
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string str[11];
int n;
int alpha[26];
vector<int> v;

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> str[i];
	}

	for (int i = 0; i < n; ++i) {
	
		for (int j = str[i].length()-1; j >= 0; --j) {
			alpha[str[i][j] - 'A'] += (int)pow(10, str[i].length() - j- 1);
		}
	}
	
	for (int i = 0; i < 26; ++i) {
		if (alpha[i])
			v.push_back(alpha[i]);
	}

	int result = 0;
	int mul = 9;

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); ++i) {
		result += (mul--) * v[i];
	}

	cout << result;
}
