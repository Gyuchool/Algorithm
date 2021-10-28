#include <iostream>
#include <string>
#include <vector>

using namespace std;
int visited[8];
string line;

string people;
int answer;
int cnt;

bool isOk(vector<string> data){
    
    for(int i=0; i<data.size(); i++){
        
        char left = data[i][0];
        char right = data[i][2];
        int dist = data[i][4] - '0';
        dist++;
        int left_index, right_index;
        
        for(int i=0; i<line.size(); i++){
            if(line[i] == left){
                left_index = i;
            }
            if(line[i] == right){
                right_index = i;
            }
        }
        
        if(data[i][3] == '='){
            if(abs(left_index-right_index) != dist){
                
                return false;
            }
            continue;
        
        }
        else if(data[i][3] == '>'){
            
            if(abs(left_index-right_index) <= dist){
                return false;
            }
            continue;
        }
        else{
            if(abs(left_index-right_index) >= dist){
                return false;
            }
            continue;
        }
    }
    
    return true;
}

void makeCase(int cnt, vector<string> data){
    if(cnt == 8){
        if(isOk(data)){
            answer++;
        }
        return;
    }
    
    for(int i=0;i<8;i++){
        if(!visited[i]){
            line+=(people[i]);
            visited[i] = 1;
            makeCase(cnt+1, data);
            line.pop_back();
            visited[i]= 0;
            
        }
    }
}
int solution(int n, vector<string> data) {
    answer = 0;
    people = "ACFJMNRT";
   
    makeCase(0, data);
    return answer;
}
