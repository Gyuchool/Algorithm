#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cnt = 0;
vector<int> v;

vector<int> makeTable(string s) {
	vector<int> table(s.size(), 0);
	int len = s.size();
	int j = 0;

	for (int i = 1; i < len; ++i) {
		while (j > 0 && s[i] != s[j]) {
			j = table[j - 1];
		}
		if (s[i] == s[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string main_str, string sub_str) {
	vector<int> table = makeTable(sub_str);
	int j = 0;
	int main_len = main_str.size();
	int sub_len = sub_str.size();

	for (int i = 0; i < main_len; ++i) {
		while (j > 0 && main_str[i] != sub_str[j]) {
			j = table[j - 1];
		}
		if (main_str[i] == sub_str[j]) {
			if (j == sub_len - 1) {
				cnt++;
				v.push_back(i - sub_len + 2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}

}
int main() {
	string t, p;
	getline(cin, t);
	getline(cin, p);
	
	KMP(t, p);
		
	cout << cnt << '\n';
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';
	}

}
