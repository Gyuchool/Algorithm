#include <string>
#include <vector>
#include <iostream>
using namespace std;


int col[13];

int answer;

bool isOk(int x){
    
    //col[i]가 의미하는 것이 X좌표, i가 의미하는것이 Y좌표
    for(int i = 0; i < x; i++){
        if(col[i] == col[x] || abs(col[x] - col[i]) == x - i){
            return false;
        }
    }
    return true;
}

void nQueen(int n, int depth){
    if(depth == n){
        answer++;
        return;
    }
    
    for(int i=0;i<n;i++){
        col[depth] = i;
        if(isOk(depth)){
            nQueen(n,depth+1);
        }
    }
    
}

int solution(int n) {
    answer = 0;
    
    nQueen(n, 0);
    
    return answer;
}

int main(){
    cout    << solution(4);
}
