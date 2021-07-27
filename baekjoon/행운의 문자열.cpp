#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, char>> v;// id, 문자
int over[27];
int visited[27];
string s;
int n;
char ans[11];
int res = 0;

int factorial(int n) {

	long long sum = 1;
	for (int i = 1; i <= n; ++i) {
		sum = sum * i;
	}
	return sum;
}
void com(int x) {
	if (x == s.size()) {
		for (int i = 0; i < x-1; ++i) {
			if (ans[i] == ans[i + 1]) {
				return ;
			}
		}
		res++;
	}

	for (int i = 0; i < s.size(); ++i) {
		if (!visited[v[i].first]) {
			visited[v[i].first] = 1;
			ans[x] = (v[i].second);
			com(x + 1);
			visited[v[i].first] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		
		over[s[i] - 'a']++;
		v.push_back({ i,s[i] });
	}

	com(0);
	int value = 1;

	for (int i = 0; i < 26; ++i) {
		if(over[i])
			value *= factorial(over[i]);
	}
	int answer = res / value;
	cout << answer;

}
