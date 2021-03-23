#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int start=0;
    int sum=people[0];
    
    for(int i=people.size()-1; i>=start; --i){
        if(sum + people[i] <=limit){
            answer++;
            start++;
            sum=people[start];
        }
        else{
            answer++;
            continue; 
        }
    }
    return answer;
}
