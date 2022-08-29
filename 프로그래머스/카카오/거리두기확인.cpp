#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> store[5];

int visited[5][5];
int dx[] = {2, 0, -2, 0, -1, -1, 1, 1};
int dy[] = {0, 2, 0, -2, -1, 1, -1, 1};
int rdx[] = {1, 0, -1, 0};
int rdy[] = {0, -1, 0, 1};

bool out(int nx, int ny);

bool bfs(vector<string> place, queue<pair<int, int>> q) {
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        visited[cx][cy] = 1;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = cx + rdx[k];
            int ny = cy + rdy[k];
            if (out(nx, ny)) {
                continue;
            }
            if (place[nx][ny] == 'P') {
                return false;
            }
        }
        for (int k = 0; k < 8; ++k) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (out(nx, ny)) {
                continue;
            }
            if (place[nx][ny] == 'P') {
                if (k < 4) {
                    if(place[(cx+nx)/2][(cy+ny)/2] != 'X'){
                        return false;
                    }
                }else{
                    if(!(place[nx][cy] == 'X' && place[cx][ny] == 'X')){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool out(int nx, int ny) { return nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny]; }

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int x=0; x<5; x++) {

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (places[x][i][j] == 'P') {
                    store[x].push({i, j});
                }
            }
        }
    }

    for (int x=0; x<5; x++) {
        answer.push_back(bfs(places[x], store[x]));
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                visited[i][j]=0;
            }
        }
    }

    return answer;
}
