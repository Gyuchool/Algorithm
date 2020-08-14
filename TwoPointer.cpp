#include <iostream>
#include <vector>
using namespace std;

int arr[4000001];
vector<int> v;
int n;

void makePrime() {
	for (int i = 2; i < 4000001;++i) {
	
		arr[i] = i;
	}
	
	for (int i = 2; i < 4000001; ++i) {
		
		if (arr[i] == 0)
			continue;
			
		for (int j = i + i; j < 4000001; j += i) {
		
			arr[j] = 0;
		}
	}
	
	for (int i = 2; i < 4000001; ++i) {
	
		if (arr[i] != 0)
			v.push_back(arr[i]);
	}

}




int main() {

	cin >> n;
	
	makePrime();
	
	int cnt = 0;
	int start = 0;
	int end = 0;
	int sum = 0;

	while(start <= end && end < v.size() && v[start] <= n) {
	
		if (sum == n) {
			cnt++;
			sum += v[end++];
		}
		
		else {
			if (sum < n) {
				sum += v[end++];
			}
			else if (sum > n) {	
				sum -= v[start++];
				
				if (start > end && start < v.size()){
					end = start;
					sum = v[start];
				}
			}
		}
	}
	
	cout << cnt;
	return 0;

}


