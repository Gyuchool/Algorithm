#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int k,n;
ll arr[100001];

int main(){

    cin>>k>>n;

    for (int i = 0; i < k; ++i) {
        cin>>arr[i];
    }
    sort(arr, arr + k);

    ll start = 1;
    ll answer = 0;
    ll end = arr[k-1];
    while (start <= end) {
        ll mid = start + (end-start)/2;
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum+=arr[i]/mid;
        }
        if(sum < n){
            end = mid -1;
        }else{
            answer = mid;
            start = mid + 1;
        }
    }

    cout <<answer;
}
