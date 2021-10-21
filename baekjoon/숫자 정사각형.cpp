#include <iostream>
using namespace std;

int n,m;
int arr[51][51];

int main(){
    cin>>n>>m;
    int answer=0;
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=1;k<min(n,m); k++){
                if(i+k>=n || j+k>=m)continue;
                if(arr[i][j] == arr[i][j+k] && arr[i][j] == arr[i+k][j] && arr[i][j] == arr[i+k][j+k]){
                    result = max(result, k);
                }
            }
            
        }
    }
    answer = (result+1)*(result+1);
    cout<<answer;
}
