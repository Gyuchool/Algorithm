#include <iostream>
using namespace std;

typedef long long ll;
ll x,y;

ll percentTo(ll mid) { return ((y + mid)*100) / (x + mid); }

int main(){
    cin>>x>>y;

    ll k = y*100/x;

    ll start = 0;
    ll end = 1000000000;
    ll answer = -1;
    while (start <= end) {
        ll mid = start + (end-start)/2;
        if (percentTo(mid) <= k) {
            start = mid+1;
        } else if (percentTo(mid) > k) {
            end = mid-1;
            answer = mid;
        }
    }
    cout << answer;
}

