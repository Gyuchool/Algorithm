#include <iostream>
#include <vector>

using namespace std;

int number=7;
bool visit[7];
vector<int> a[8];

void dfs(int x){
	if(visit[x])return;
	visit[x]=true;
	cout << x << ' ';
	for(int i=0; i<a[x].size(); ++i){
		dfs(a[x][i]);
	}
}
int main(){
	a[1].push_back(2);
	a[2].push_back(1);
	//1 2 connect
	a[1].push_back(3);
	a[3].push_back(1);
	//1 3 connect
	a[2].push_back(3);
	a[3].push_back(2);
	//2 3 connect
	a[2].push_back(4);
	a[4].push_back(2);
	//2 4 connect
	a[2].push_back(5);
	a[5].push_back(2);
	//2 5 connect
	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);
	dfs(1);
	return 0;

}
