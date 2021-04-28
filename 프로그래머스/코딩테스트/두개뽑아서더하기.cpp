#include <string>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> ans;
    for(int i=0; i<numbers.size(); ++i){
        for(int j=i+1; j<numbers.size(); ++j){
            
            ans.insert(numbers[i]+numbers[j]);
        }
    }
   for(auto it = ans.begin(); it != ans.end(); it++){
		answer.push_back(*it);
	}
    return answer;
}
