#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<char> stack;

string reverse(string s) {
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		tmp = s[i] + tmp;

	}
	return tmp;
}

int main() {
	
	getline(cin, s);
	string keep = "";
	string rever = "";
	string answer = "";
	int flag = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			if (!rever.empty()) {
				answer += reverse(rever);
				rever = "";
			}
			flag = 1;
			keep = "<";
			continue;
		}
		else if (s[i] == '>') {
			flag = 0;
			keep += '>';
			answer += keep;
			continue;
		}
		else if (flag == 0 && s[i] == ' ') {
			if (!rever.empty()) {
				answer += reverse(rever)+' ';
				rever = "";
			}
			continue;
		}
		
		if (flag == 1) {
			keep += s[i];
		}
		else {
			rever += s[i];
		}
	}
	if (!rever.empty()) {
		answer += reverse(rever) + ' ';
	}
	cout << answer;
}
