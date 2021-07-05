#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	string s;
	cin >> s;
	int i = 0;
	int count = 0;
	while (i<s.length()) {
		if (s[i] == 'c') {
			if (s[i + 1] == '=' || s[i + 1] == '-') {
				count++;
				i = i + 2;
			}
			else {
				count++; i++;
			}
		}
		else if (s[i] == 'd') {
			if (s[i + 1] == '-') {
				count++; i += 2;
			}
			else if (s[i + 1] == 'z' && s[i + 2] == '=') {
				count++; i +=3;
			}
			else {
				count++; i++;
			}
		}
		else if (s[i] == 'l') {
			if (s[i + 1] == 'j') {
				count++; i += 2;
			}
			else {
				count++; i++;
			}
		}
		else if (s[i] == 'n') {
			if (s[i + 1] == 'j') {
				count++; i += 2;
			}
			else {
				count++; i++;
			}
		}
		else if (s[i] == 's') {
			if (s[i + 1] == '=') {
				count++; i += 2;
			}
			else {
				count++; i++;
			}
		}
		else if (s[i] == 'z') {
			if (s[i + 1] == '=') {
				count++; i += 2;
			}
			else {
				count++; i++;
			}
		}
		else {
			count++; i++;
		}
		
	}
	cout << count;
}
