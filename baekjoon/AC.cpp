#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	string func;
	int n;
	string list;

	for (int i = 0; i < t; ++i) {
		cin >> func >> n>>list;
		string tmp = list.substr(1, list.size() - 2);
		int startIndex = 0;
		int findIndex = tmp.find(",", startIndex);
		deque<string> dq;
		int error = 0;
		
		while (findIndex != -1) {
			dq.push_back(tmp.substr(startIndex, findIndex - startIndex));
			startIndex = findIndex + 1;
			findIndex = tmp.find(",", startIndex);
		
		}
		dq.push_back(tmp.substr(startIndex));
		
		int is = 1;
		if (n == 0) {
			is = 0;
		}
		int reverse = 0;
	
		for (int j = 0; j < func.size(); ++j) {
			if (dq.empty()) {
				
				is = 0;
			}
			if (func[j] == 'R') {
				if (reverse) {
					reverse = 0;
				}
				else {
					reverse = 1;
				}
			}
			if (func[j] == 'D') {
			
				if (!is) {
					error = 1;
					break;
				}
				else if (reverse) {
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}
			}
		}
		if (error) {
			cout << "error" << '\n';
		}
		else {
			if (dq.empty()) {
				cout << "[]" << '\n';
			}
			else {
				if (!reverse) {
					string answer = "[";
					for (int k = 0; k < dq.size() - 1; ++k) {
						answer += dq[k];
						answer += ",";
					}
					answer += dq[dq.size() - 1];
					answer += "]";

					cout << answer << '\n';
				}
				else {
					string answer = "[";
					for (int k = dq.size()-1; k >0; --k) {
						answer += dq[k];
						answer += ",";
					}
					answer += dq[0];
					answer += "]";

					cout << answer << '\n';
				}
				
			}
		}

	}
}
