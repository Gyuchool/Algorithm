#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> w;
vector<int> h;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(int i=0; i<sizes.size(); i++){
        int ma = max(sizes[i][0], sizes[i][1]);
        int mi = min(sizes[i][0], sizes[i][1]);
        w.push_back(ma);
        h.push_back(mi);
        
    }
    sort(w.begin(), w.end());
    sort(h.begin(), h.end());
    answer = w[w.size()-1]*h[h.size()-1];
    return answer;
}
