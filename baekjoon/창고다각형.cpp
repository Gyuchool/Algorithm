#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x,y;
vector<pair<int, int>> v;

int main(){
    cin>>n;
    int top=0;
    for (int i = 0; i <n; ++i) {
        cin>>x>>y;
        top = max(y, top);
        v.push_back({x, y});

    }
    if (n == 1) {
        cout<< top;
        return 0;
    }
    sort(v.begin(), v.end());

    int sum = 0;
    int start_i=v[0].first;
    int start_h=v[0].second;
    int end_i=v[v.size()-1].first;
    int end_h=v[v.size()-1].second;

    int start_idx=0;
    int end_idx=0;
    for (int i = 1; i < v.size(); ++i) {
        if (start_h < v[i].second) {
            sum+= (v[i].first-start_i)*start_h;
            start_i = v[i].first;
            start_h = v[i].second;

        }
        if (start_h == top) {
            start_idx = start_i;
            break;
        }
    }

    for (int i = v.size()-1; i >= 0; --i) {
        if (end_h < v[i].second) {
            sum+= (end_i-v[i].first)*end_h;
            end_i = v[i].first;
            end_h = v[i].second;

        }
        if (end_h == top) {
            end_idx = end_i;
            break;
        }
    }

    sum+=top*abs(end_idx - start_idx+1);
    cout <<sum;
}
