#include <iostream>
#include <regex>
using namespace std; 
int main() { 
	regex re("(100+1+|01)+"); 
	cmatch m; 
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		string seq;
		cin >> seq;
		bool ans = regex_match(seq.c_str(), m, re);
		cout << (ans ? "YES" : "NO") << '\n';
	}
	
	return 0; 
}

