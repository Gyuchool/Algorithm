#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];//수열 크기
int n;
vector<int> v;
int start;
int ans = 0;

void lis(int index){
	for(int i=0; i<v.size(); ++i){
		if(v[i] >= arr[index]){//i번 자리에 들어가야함
			v[i]=arr[index];
			break;
		}
	}
}

int Per_size(int arr[]) {
		
	v.push_back(-1);//초기화 <시작>

	for (int i = 0; i < n; ++i) {
		int PeekIndex = v.size() - 1;
		if (arr[i] > v[PeekIndex]) {
			v.push_back(arr[i]);
			ans++;
		}
		else {
			lis(i);
		}
	}

	return ans;
}

int main() {

	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	cout << Per_size(arr) <<endl;;
	return 0;
}
