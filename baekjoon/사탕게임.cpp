#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s[51];

void swap(int i, int j){
    
    char tmp = s[i][j];
    s[i][j] = s[i][j+1];
    s[i][j+1] = tmp;
}

void swap2(int i, int j){
    char tmp = s[i][j];
    s[i][j] = s[i+1][j];
    s[i+1][j] = tmp;
}
int check(){
    int ma = 0;
    int cnt = 1;
    for(int i=0; i<n; i++){
        cnt = 1;
        for(int j=0;j<n - 1;j++){
            if(s[i][j] == s[i][j+1]){
                cnt++;
                ma = max(cnt, ma);
            }
            else{
                cnt = 1;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        cnt = 1;
        for(int j=0;j<n - 1;j++){
            if(s[j][i] == s[j+1][i]){
                cnt++;
                ma = max(cnt, ma);
            }
            else{
                cnt = 1;
            }
        }
    }
    ma = max(cnt, ma);
    return ma;
}


int main(){
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int answer=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
                swap(i,j); // 바꿔서 테스트
                int result = check();
                answer = max(result, answer);
                swap(i,j); // 원래대로 되돌려놓기
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            
                swap2(j,i);
                int result = check();
                answer = max(result, answer);
                swap2(j,i);
        }
    }
    
    cout<<answer;
}
