#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main(){
    int n;
    int sum=1;
    cin>>n;
    
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(int i=0; i<n;++i){
        if(arr[i] > sum){
            break;
        }
        sum+=arr[i];
    }
    
    cout<<sum;
    
}
