#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void R_Per(vector<int>& arr, int start, int end) {
	int last = arr[end];
	for (int i = end; i > start; i--) {
		arr[i] = arr[i - 1];
	}

	arr[start] = last;
}

void L_Per(vector<int>& arr, int start, int end) {
	int first = arr[start];
	for (int i = start; i < end; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[end] = first;
}

void Permutation(vector<int>& arr, int start, int end) {
	if (start == end ) {
		for (int i = 0; i < arr.size(); ++i) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	else {
		for (int i = start; i < end; ++i) {
			R_Per(arr, start, i);
			Permutation(arr, start+1, end);
			L_Per(arr, start, i);
		}
	}
}


int main() {
	int n;//n이 끝인 수열 1,2,~ n
	int k;//k==1, x번째 수열 ,, k==2, arr이 몇번째 수열인지
	int x;
	int cnt = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		v.push_back(i + 1);//1~n vector storage
	}
	Permutation(v, 0, n);

}
