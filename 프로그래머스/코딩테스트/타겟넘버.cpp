#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int target, int i,int& answer, int result){

    if(i == numbers.size()){
        if(result == target)answer++;   
        return;
    }

    dfs(numbers,target, i+1, answer, result+numbers[i]);
    dfs(numbers,target, i+1, answer, result-numbers[i]);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, answer, 0);
    return answer;
}
