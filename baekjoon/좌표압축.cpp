#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n;
map<int, int> mp;
vector<pair<int, int>> v;

int main() {
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v.push_back({x, i});
    }

    sort(v.begin(), v.end());

    int idx = 0;

    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i].first != v[i + 1].first) {
            mp[v[i].second] = idx++;
        } else {
            mp[v[i].second] = idx;
        }
    }
    mp[v[v.size() - 1].second] = idx;

    for (int i = 0; i < mp.size(); ++i) {
        cout << mp[i] << ' ';
    }
}
