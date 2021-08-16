#include <iostream>
#include <string>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	string s;
	string ans = "";
	int cnt = 0;
	int check = 0;
	cin >> s;
	ans = s[0];
	if (n == m) {
		return 0;
	}
	for (int i = 1; i < s.size(); ++i) {
		
		if (ans[ans.size() - 1] < s[i]) {
			ans.pop_back();
			cnt++;
			if (ans.empty()) {
				ans += s[i];
				i++;

			}
			i--;
		}
		else {
			
			
			ans += s[i];
		}
		if (cnt == m) {
			
			ans += s.substr(i+1);
			break;
		}

	}

	if (cnt < m) {
		int t = m - cnt;
		for (int i = 0; i < t; ++i) {
			ans.pop_back();
		}
	}
	
	cout << ans << endl;
}
