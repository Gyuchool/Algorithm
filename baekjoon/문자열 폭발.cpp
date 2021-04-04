#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
using namespace std;

string c;
string s;
string boom;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	
	int del = 0;
	cin >> c;

	cin >> boom;
	int i;
	int last = boom.length() - 1;//boom의 마지막 문자
	for (i = 0; i < c.length(); ++i) {
		s += c[i];
		
		if (boom[last] == c[i] && i>=last) {
			del = 0;
			for (int j = 1; j < boom.length(); ++j) {
				if (boom[last - j] != s[s.size()-1 - j]) {
					del = 1;
				}
				
			}
			if (del == 0) {
				for (int j = 0; j < boom.length();++j) {
					s.pop_back();
				}
				
			}

		}
		
	}
	if (s.size() == 0) {
		cout << "FRULA";
	}
	else {
		cout << s;
	}

}
