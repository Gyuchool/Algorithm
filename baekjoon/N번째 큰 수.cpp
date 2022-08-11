#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int t,n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>> t;
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            cin>>n;
            pq.push(n);
            if (pq.size() > t) {
                pq.pop();
            }
        }
    }
    cout<<pq.top();
}
