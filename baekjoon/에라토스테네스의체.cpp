#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int count = 0;
	int check = 0;
	int arr[1001]={ 0, };
	for (int i = 2; i <= n; ++i) {
		arr[i] = i;
	}
	for (int i = 2; i <= n; ++i) {
		if (arr[i] == 0) {
			continue;
		}
		else {
			count++;//count=1,
			if (count == k) {//0==4//
				cout << arr[i];
				break;
			}
			arr[i] = 0;
			
			for (int j = 2 * i; j <= n; j += i) {	
				if (arr[j] == 0)
					continue;
				count++;//2==4.3
				if (count == k) {//1==4,2==4,
					cout << arr[j];
					check = 1;
					break;
				}
				
				arr[j] = 0;
				
				
			}
			if (check == 1)
				break;
		}
		
	}

}
