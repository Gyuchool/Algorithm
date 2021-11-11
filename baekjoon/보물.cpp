#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[101];
int B[101];

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
        
    sort(A, A+n);
    sort(B, B+n, greater<>());
    int sum=0;
    
    for(int i=0;i<n;i++){
        sum+=A[i]*B[i];
    }
    cout<<sum;
}
