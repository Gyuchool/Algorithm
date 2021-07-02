#include <iostream>
using namespace std;


int n;
int arr[17][17];
int result = 0;

typedef struct {
	int x, y;
}Dir;

Dir dir[] = { {0,1}, {1,0}, {1,1} };
//d 0, 1, 2 <- 가로 세로 대각선

void bfs(int x, int y, int d) {

		if (x == n - 1 && y == n - 1) {
			result++;
			return;
		}

		for (int i = 0; i < 3; ++i) {

			if ((i == 0 && d == 1) || (i == 1 && d == 0)) {
				continue;
			}

			int nx = x + dir[i].x;
			int ny = y + dir[i].y;
			if (nx >= n || ny >= n || arr[nx][ny] == 1)continue;
			
			if (i == 2 && (arr[x + 1][y] == 1 || arr[x][y + 1] == 1))continue;

			bfs(nx, ny, i);
		}
}
int main() {
	
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	bfs(0, 1, 0);
	cout << result;

}
