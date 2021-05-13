#include <string>
#include <vector>

using namespace std;
 int visited[46]= {0,};
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
   
    int zero=0; //0 개수
    int cnt=0; //일치 횟수
    int rank = 0;
    for(int i=0; i<lottos.size(); ++i){
        if(lottos[i] == 0){
                zero++;
                continue;
        }
        for(int j=0;j<win_nums.size();++j){
            
            if(!visited[j]){
                if(lottos[i] == win_nums[j]){
                    visited[win_nums[j]]++;
                    cnt++;
                    break;
                }
            }
        }
    }
    rank = 7-zero-cnt;
    if(rank>5){
        rank=6;
    }
    answer.push_back(rank);
    rank = 7-cnt;
    if(rank>5){
        rank=6;
    }
    answer.push_back(rank);
    return answer;
}
