#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001];
int weight[100001]; //물건당 무게
int value[1001]; //물건당 가치
int n, k; //물품의 수, 버틸수있는 무게

int Value(int size, int sumWeight){
	
	if(size == -1){
		return 0;
	}
	if(dp[size][sumWeight]){
		return dp[size][sumWeight];
	}

	int in = 0;
	if(sumWeight + weight[size] <= k){
		in = value[size] + Value(size - 1, sumWeight + weight[size]); //물건을 넣었을 때
	}
	int Noin = Value(size - 1, sumWeight);

	return dp[size][sumWeight] = max(in, Noin);
}


int main(){
	
	cin >> n >> k;

	for(int i = 0; i < n; ++i){
		cin >> weight[i] >> value[i];
	}

	cout << Value(n-1, 0);


	return 0;
}
