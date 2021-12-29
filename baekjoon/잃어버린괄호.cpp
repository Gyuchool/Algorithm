//1541 baekjoon
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;	int sum = 0;	int count = 0;	int startIndex = 0;	int check = 0;//-사이에 있으면 1
	getline(cin, s, '\n');	
	string tmp;	int len = s.length();
	int fIndex_ = s.find('-', startIndex);
	for (int i = 0; i < len; i++) {
		if (s[i] == '+' && check==0) {
			count = i - startIndex;
			tmp = s.substr(startIndex, count);
			sum += stoi(tmp);
			startIndex = i + 1;
		}
		else if (s[i] == '+' && check == 1) {
			count = i - startIndex;
			tmp = s.substr(startIndex, count);
			sum -= stoi(tmp);
			startIndex = i + 1;
		}
		else if (s[i] == '-' && check==1) {
			count = i - startIndex;
			tmp = s.substr(startIndex, count);
			sum -= stoi(tmp);
			startIndex = i + 1;
		}
		else if (s[i] == '-' && check == 0) {
			count = i - startIndex;
			tmp = s.substr(startIndex, count);
			sum += stoi(tmp);
			startIndex = i + 1;
			check = 1;
		}
		if (s.find('+', i + 1) == -1 && s.find('-', i + 1) == -1 && check==1) {
			tmp = s.substr(startIndex);
			sum -= stoi(tmp);
			break;
		}
		else if (s.find('+', i + 1) == -1 && s.find('-', i + 1) == -1 && check == 0) {
			tmp = s.substr(startIndex);
			sum += stoi(tmp); 
			break;
		}
	}
	cout << sum;
}
