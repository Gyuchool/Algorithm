#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
vector<string> v;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	
	int len = v[0].size();
	int flag = 0;
	string answer = "";

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < v.size()-1; j++) {
			if (v[j][i] == v[j+1][i]) {
				flag = 0;
			}
			else { //abbb abbc
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			answer += '?';
		}
		else {
			answer += v[0][i];
		}
	}
	cout << answer;
}
