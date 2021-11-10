#include <iostream>
#include <algorithm>
using namespace std;

int n, k;//버틸수있는 무게
int w[100001];//물건의 무게
int v[1001];//가치 크기
int dp[1001][100001];
int Value(int size, int startW) {

	if (size == -1) {
		return 0;
	}
	if (dp[size][startW])
		return dp[size][startW];
	int In = 0;
	if (startW + w[size] <= k) 
		In = v[size] + Value(size - 1, startW + w[size]);
	int NoIn = Value(size-1, startW);
	
		
	return dp[size][startW] = max(NoIn, In);
	
	
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> v[i];
	}
	cout << Value(n-1, 0);


}
