#include <iostream>
#include <algorithm>

using namespace std;

int n;//도시갯수
int m;//버스의 개수

int INF = 100000010;
int arr[101][101];//도시, 버스
int answer[101][101];
int a, b, c;//시작, 도착, 비용

void floydWarshall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; ++j) {	

			if (i == j) {
											
				answer[i][j] = 0;
			}
			else {	
				if (arr[i][j] == 0) {
					answer[i][j] = INF;
				}
				else {
					answer[i][j] = arr[i][j];
				}
			}
		}
	}
	
	for (int k = 0; k < n; ++k){//k = 거쳐가는 노드
		for (int i = 0; i < n; ++i) {//i = 출발 노드
			for (int j = 0; j < n; ++j) {//j = 도착 노드
				if (answer[i][k] + answer[k][j] < answer[i][j]) {
					answer[i][j] = answer[i][k] + answer[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
									
			if (answer[i][j] == INF) {
				answer[i][j] = 0;
			}
													
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		if (arr[a - 1][b - 1]) {
			arr[a - 1][b - 1] = min(arr[a - 1][b - 1], c);
		}
		else {
			arr[a-1][b-1] = c;
		}			
	}

	floydWarshall();

	return 0;
}
