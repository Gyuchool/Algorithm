#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;
int n;
int v[10001];
int arr[10001];


int main() {
	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> n;

		for (int j = 0; j < n; ++j) {
			cin >> arr[j];
		}
		sort(arr, arr + n);
		//큰수부터 가운대에서 넣기
		int index = (n / 2);
		int k = 1;
		int check = 0;
		v[index] = arr[n - 1];
		for (int j = n - 2; j >= 0; j--) {
			if (arr[j] && check==0) {
				v[index - k] = arr[j];
				check = 1;
			}
			else if (arr[j] && check==1) {
				v[index + k] = arr[j];
				k++;
				check = 0;
			}
			
		}
		
		int ma = -1;
		for (int i = 0; i < n-1; ++i) {
			ma = max(ma, abs(v[i] - v[i + 1]));
		}
		cout << ma << endl;
	}
}


