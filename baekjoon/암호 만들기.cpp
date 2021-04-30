#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> v;
vector<char> ans;
int l, c;
int cnt;//모음
int visited[28];

int ncnt = 0;//자음

void make(int size, int start) {
	if (size == l) {
		if (cnt == 0) {//모음없으면
			return;
		}
		if (ncnt < 2) {//자음 2개 미만
			return;
		}
		else {
			for (int i = 0; i < size; ++i) {
				cout << ans[i];
			}
			cout << '\n';
			
		}
	
	}

	for (int i = start; i < c; ++i) {
		if (!visited[v[i] - 'a']) {
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
				cnt++;
			}
			else {
				ncnt++;
			}
			ans.push_back(v[i]);
			visited[v[i] - 'a'] = 1;
			make(size + 1, i+1);
			if (ans[ans.size() - 1] == 'a' || ans[ans.size() - 1] == 'e' || ans[ans.size() - 1] == 'i' || ans[ans.size() - 1] == 'o' || ans[ans.size() - 1] == 'u') {
				cnt--;
			}
			else {
				ncnt--;
			}
			ans.pop_back();
			visited[v[i] - 'a'] = 0;
		}
	}

}
int main() {

	
	cin >> l >> c;
	char x;
	for (int i = 0; i < c; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	make(0,0);

}
