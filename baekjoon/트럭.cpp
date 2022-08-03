#include <iostream>
#include <queue>

//13335
using namespace std;

int arr[1001];
int n, w, l;//트럭수, 다리길이, 최대하중

queue<int> q;

int main() {
    cin >> n >> w >> l;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cw = 0;
    int t = 0;
    int start = 0;
    int last =0;
    bool out = false;

    while (start < n) {
        if (q.size() == w) {
            int value = q.front();
            q.pop();
            cw -= value;
        }
        if (cw + arr[start] <= l) {
            q.push(arr[start]);
            cw += arr[start];
            start++;
            last = 1;
        } else {
            last++;
            q.push(0);
        }
        t++;
    }

    if (!q.empty()) {
        t = t + (w-last+1);
    }
    cout << t;

}

