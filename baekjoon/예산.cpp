#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10001];
int total;

int main(){
    cin>>n;
    int answer=0;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cin>>total;
    sort(arr, arr + n);

    int start=0;
    int end = arr[n-1];
    while (start <= end) {
        int sum=0;
        int mid = start + (end-start)/2;
        for (int i = 0; i < n; ++i) {
            sum += min(arr[i], mid);
        }
        if (sum > total) {
            end = mid-1;
        }else{
            answer = mid;
            start = mid +1;
        }
    }

    cout<<answer;
}
