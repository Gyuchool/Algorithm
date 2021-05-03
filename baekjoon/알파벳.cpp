#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int alpha[27];//알파벳 사용했는지 a~z
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
char arr[21][21];
int r, c;//세로 가로

vector<int> v;
int check;

void dfs(int x, int y, int cnt) {

	
	
	for (int i = 0; i < 4; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx < 0 || cy < 0 || cx >= r || cy >= c)
			continue;
		if (alpha[arr[cx][cy] - 'A'] == 1) {
			if (cnt > check) {
					check = cnt;
					continue;
			}
		}
	
		if ( alpha[arr[cx][cy]-'A'] == 0) {
		
			alpha[arr[cx][cy] - 'A'] = 1;
			dfs(cx, cy, cnt + 1);
			alpha[arr[cx][cy] - 'A'] = 0;
		
		}

	}

}

int main() {
	
	cin >> r >> c;//세로 가로

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> arr[i][j];
		}
	}

	alpha[arr[0][0] - 'A'] = 1;//alpha가 0이면 이동가능 
	
	check = 1;
	dfs(0, 0, 1);

	
	
	cout << check;


	
}
