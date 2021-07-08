#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3];
int check = 0;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	int n;
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> arr[i][j];
		}
		
	}

	for (int i = 1; i < n; ++i) {
		arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]);
	}

	cout << min(arr[n - 1][0], min(arr[n - 1][1], arr[n - 1][2]));


}
