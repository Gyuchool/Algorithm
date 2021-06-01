#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0; i<prices.size()-1; ++i){
        int tmp=prices[i];
        int id=0;
        for(int j=i+1; j<prices.size(); ++j){
            id++;
            if(prices[j] < tmp){
                break;
            }
        }
        answer.push_back(id);
    }
    answer.push_back(0);
    return answer;
}
