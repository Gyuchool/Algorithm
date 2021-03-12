#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int arr[1001];
int n, m;

class Kru {
	public:
	int node[2];
	int cost;
	Kru(int a,int b, int c) {
		this->node[0] = a;
		this->node[1] = b;
		this->cost = c;
	}
	bool operator<(Kru& kru) {
		return this->cost < kru.cost;
	}
};

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
		return parent[x] = getParent(parent, parent[x]);
}

void Merge(int parent[], int x, int y) {
	int a = getParent(parent, x);
	int b = getParent(parent, y);

	if (a == b)
		return;
	else if(a > b){
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}

bool findParent(int parent[], int x, int y) {
	int a = getParent(parent, x);
	int b = getParent(parent, y);
	if (a == b)
		return true;
	else
		return false;
}


int main() {
	vector<Kru> v;
	cin >> n >> m;//컴퓨터 수 , 연결할 수 
	int a, b, c;
					
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		v.push_back(Kru(a, b, c));//a->b cost: c
	}

	sort(v.begin(), v.end());//cost기준으로 정렬
	
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
	}
	int sum = 0;

	for (int i = 0; i < v.size(); ++i) {
	
		if (!findParent(arr, v[i].node[0] - 1, v[i].node[1] - 1)) {//사이클이 발생하지 않는 경우
		
			sum += v[i].cost;
			Merge(arr, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	
	cout << sum;
	return 0;

}
