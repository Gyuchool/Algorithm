#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    for(int j=10000; j>=0; j--){
        int big=0;
        int small = 0;
        for(int i=0; i<citations.size(); i++){
            if(citations[i] >= j){
                big++;
            }
            else{
                small++;
            }
        }        
        if(big>=j && small<=j){
            answer = j;
            break;
        }
    }
    
    return answer;
}
