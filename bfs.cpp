#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//7개 관리
int numbers = 7;
bool visit[7];
vector<int> a[8];

void bfs(int start){
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout<< x ;
		for(int i=0; i< a[x].size(); ++i){
			int y = a[x][i];
			if(!visit[y]){
				visit[y] = true;
				q.push(y);
			}
		}
	}
	cout << endl;
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

	bfs(1);
	return 0;
}
