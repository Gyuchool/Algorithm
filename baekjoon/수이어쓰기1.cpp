#include <vector>
#include <iostream>

using namespace std;

long long n;

int main() {
    cin >> n;

    if (n < 10) {
        cout << n;
    } else if (n < 100) {
        cout << 9 + (n - 9) * 2;
    } else if (n < 1000) {
        cout << 9 + 180 + (n - 99) * 3;
    } else if (n < 10000) {
        cout << 9 + 180 + 2700 + (n - 999) * 4;
    } else if (n < 100000) {
        cout << 9 + 180 + 2700 + 36000 + (n - 9999) * 5;
    } else if (n < 1000000) {
        cout << 9 + 180 + 2700 + 36000 + 450000 + (n - 99999) * 6;
    } else if (n < 10000000) {
        cout << 9 + 180 + 2700 + 36000 + 450000 + 5400000 + (n - 999999) * 7;
    } else if (n < 100000000) {
        cout << 9 + 180 + 2700 + 36000 + 450000 + 5400000 + 63000000 + (n - 9999999) * 8;
    } else {
        cout << 9 + 180 + 2700 + 36000 + 450000 + 5400000 + 63000000 + 720000000 + 9;
    }
}
