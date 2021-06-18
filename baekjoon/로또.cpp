
#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[13];
int isused[13];
int tmp[13];
int k = 0;

//sizeC6
//arrC6
void go(int start, int k) {
	
	if (k == 6) {
		for (int i = 0; i < 6; ++i) {
			cout << tmp[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; ++i) {
		
			tmp[k] = arr[i];
			
			go(i+1, k+1);
		
	}


}
int main() {
	
	cin >> n;
	while (n != 0) {
		
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		go(0, 0);
		cout << "\n";
		cin >> n;

	}
	return 0;
}
