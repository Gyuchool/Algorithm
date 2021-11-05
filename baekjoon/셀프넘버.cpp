#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[20000];

int d(int x){
    int res= x;
    
    while(x!=0){
        int tmp = x%10;
        x/=10;
        res+=tmp;
    }
    return res;
    
}
int main(){
    
    for (int i =1; i<=10000; i++) {
        dp[d(i)]++;
        
    }
    
    for (int i =1; i<=10000; i++) {
        if(dp[i] == 0){
            cout<<i<<endl;
        }
        
    }
}
