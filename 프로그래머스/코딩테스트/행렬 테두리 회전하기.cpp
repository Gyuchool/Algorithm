#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int map[101][101];
int m = 100001;

void rotation(int lx, int ly, int rx, int ry) {

    int tmp2 = map[lx + 1][ly];

    for (int i = ly; i <= ry; i++) {
        int tmp = map[lx][i];
        map[lx][i] = tmp2;
        tmp2 = tmp;
        m = min(m, tmp);
    }
    for (int i = lx + 1; i <= rx; i++) {
        int tmp = map[i][ry];
        map[i][ry] = tmp2;
        tmp2 = tmp;
        m = min(m, tmp);
    }
    for (int i = ry - 1; i >= ly; i--) {
        int tmp = map[rx][i];
        map[rx][i] = tmp2;
        tmp2 = tmp;
        m = min(m, tmp);
    }
    for (int i = rx - 1; i >= lx + 1; i--) {
        int tmp = map[i][ly];
        map[i][ly] = tmp2;
        tmp2 = tmp;
        m = min(m, tmp);
    }

}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int n = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j] = n++;
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        m = 100001;

        rotation(queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1);
        answer.push_back(m);
    }
    return answer;
}
