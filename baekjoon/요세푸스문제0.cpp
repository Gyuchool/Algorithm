#include <string>
#include <vector>
#include <iostream>
using namespace std;

int n,k;
vector<int> arr;
int visited[1001];
vector<int> answer;

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        arr.push_back(i+1);
    }
    
    int nx =0;
    for(int i=0;i<n;i++){
        nx = nx+k-1;
        nx = nx%arr.size();
        answer.push_back(arr[nx]);
        arr.erase(arr.begin()+nx);
    }
    cout<<"<";
    for (int i=0; i<answer.size()-1; i++) {
        cout<<answer[i]<<", ";
    }
    cout<<answer[answer.size()-1]<<">";
}
