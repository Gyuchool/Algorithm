#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int visited[51];
int ma = 10000;

void dfs(string begin, string target, vector<string> words, int answer) {

    if (begin == target) {
        ma = min(answer, ma);
      
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if (words[i][j] != begin[j]) {
                cnt++;
            }
        }

        if(cnt == 1) {
            if (!visited[i]) {
                visited[i] = 1;
                dfs(words[i], target, words, answer + 1);
                visited[i] = 0;
            }
        }
    }

}
int solution(string begin, string target, vector<string> words) {
    string tmp = begin;

    dfs(tmp, target, words, 0);
    if (ma <= 50) {
        return ma;
    }
    return 0;
   
}
