#include <iostream>
using namespace std;
//1, 4, 10,
//1, 3, 6, 10, 15,
//1, 2, 3, 4, 5, 6, 7, 8, 9
int dp[15][15];

int main(){
    int t;
    int k,n;

    cin>>t;
    for (int i = 1; i < 15; ++i) {
        dp[0][i] = i;
        dp[i][1] = 1;
    }

    for (int i = 1; i < 15; ++i) {
        for (int j = 1; j < 15; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    for (int i = 0; i < t; ++i) {
        cin>>k>>n;
        cout<<dp[k][n]<<endl;
    }
}
