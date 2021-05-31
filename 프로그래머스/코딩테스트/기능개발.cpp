#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int k;
    int id = 0;
    
    for(int i=0; i<progresses.size(); ++i){
        k=(100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]){
            k++;
        }
        q.push(k);
    }//걸린시간 q에 저장완료
    int max=q.front();
    while(!q.empty()){
        if(q.front()<=max){
            q.pop();
            id++;
            
        }
        else{
            answer.push_back(id);

            max=q.front();
            id=0;
        }
    }
    
    answer.push_back(id);
    return answer;
}
