#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
string s[10001];

int main(){
    cin>>n>>m;

    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    string input;
    int cnt=0;
    sort(s, s + n);
    for (int i = 0; i < m; ++i) {
        cin>>input;
        if (binary_search(s, s + n, input)) {
            cnt++;
        }
    }
    cout<<cnt;

}
