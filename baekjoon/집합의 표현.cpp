#include <iostream>
using namespace std;

int parent[1000001];

int getP(int p[], int x) {
	if (p[x] == x)
		return x;
	return p[x] = getP(p, p[x]);
}
void merge(int p[], int x, int y) {
	int a = getP(p, x);
	int b = getP(p, y);

	if (a == b)
		return;
	else if (a > b) {
		p[a] = b;
	}
	else {
		p[b] = a;
	}
}
bool FindP(int p[], int x, int y) {
	int a = getP(p, x);
	int b = getP(p, y);

	if (a == b)
		return true;
	else
		return false;
}
int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	int a, b, c;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
	}
	
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		if (a == 0) {
			merge(parent, b, c);
		}
		else if (a == 1) {
			if (FindP(parent, b, c)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}
