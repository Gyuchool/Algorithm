#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[1001][1001];
int answer[1001][1001];
int INF = 100000000;
int n, m, x;

void floydWarshall() {
	for (int i = 0; i < n; ++i) {//초기화
		for (int j = 0; j < n; ++j) {
			if (i == j)
				answer[i][j] = 0;
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
	
	for (int k = 0; k < n; ++k) {//거치기
		for (int i = 0; i < n; ++i) {//출
			for (int j = 0; j < n; ++j) {//도
				if (answer[i][k] + answer[k][j] < answer[i][j]) {
					answer[i][j] = answer[i][k] + answer[k][j];
				}
			}
		}
	}

}

int main() {
	int a, b, c;//a->b : c
	cin >> n >> m >> x;//n명 학생, m개의 도로, x노드
	int d = x - 1;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		arr[a-1][b-1] = c;
	}
	
	floydWarshall();
	int max;
	for (int i = 0; i < n; ++i) {
		max = answer[i][d] + answer[d][i];
		for (int j = 0; j < n; ++j) {
			if (max < answer[j][d] + answer[d][j]) {
				max = answer[j][d] + answer[d][j];
			}
		}
	}
	cout << max;
}
