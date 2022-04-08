#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int t;
	int len;
	int x1, y1, r1, x2, y2, r2;
	cin >> t;
	for (int i = 0; i < t; ++i) {

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				cout << -1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			len = (pow((x2 - x1), 2) + pow((y2 - y1), 2));//len^2
			if (len == pow((r1 + r2),2)) {//외접할때
				cout << 1 << '\n';
			}
			else if(len > pow(r1 + r2,2)){//바깥에서 접하지 않을때
				
				cout << 0 << '\n';
			}
			else {

				if (pow((r2 - r1),2) == len) {//내접할때
					cout << 1 << '\n';
				
				}
				else if (pow((r2 - r1),2) > len) {//안에서 안접할때
					cout << 0 << '\n';
				
				}
				else {
					cout << 2 << '\n';
				}
				
			}
		
		}

	}
}
