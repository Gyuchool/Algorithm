#include <iostream>
using namespace std;

int main() {
	long long a, b, c;
	long long x1, x2, y1, y2;
	cin >> a >> b >> c;

	cin >> x1 >> x2 >> y1 >> y2;


	if (a == 0) {
		long long t = b * y1 + c;
		long long x = b * y2 + c;

		if (t * x < 0) {
			cout << "Poor";
		}
		else {
			cout << "Lucky";
		}
	}
	else if(b==0){
		long long t = a * x1 + c;
		long long x = a * x2 + c;

		if (t * x < 0) {
			cout << "Poor";
		}
		else {
			cout << "Lucky";
		}

	}
	else if (a * b < 0) {
		
		long long t1 = (a * x1) + (b * y2) + c;
		long long t2 = (a * x2) + (b * y1) + c;
		if (t1 * t2 < 0) {
			cout << "Poor";
		}
		else {
			cout << "Lucky";
		}
	}
	else{

		long long t1 = (a * x1) + (b * y1) + c;
		long long t2 = (a * x2) + (b * y2) + c;

		if (t1 * t2 < 0) {
			cout << "Poor";

		}
		else {
			cout << "Lucky";
		}
	}


}
