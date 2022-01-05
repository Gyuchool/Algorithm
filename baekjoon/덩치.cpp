#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
	vector <pair <int ,int>> p;
	int check[100] = { 0, };
	
	int test_f,test_s;
	int n,a,b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		p.push_back(make_pair(a, b));	
	}

	for (int j = 0; j < n; j++) {
		int count = 1;
		test_f = p[j].first;
		test_s = p[j].second;
		for (int i = 0; i < n; i++) {
			if (p[i].second > test_s && p[i].first > test_f){
				count++;
			}

		}
		check[j]=count;
	}

	for (int i = 0; i < n; i++) {
		cout << check[i] << ' ';
	}

}
