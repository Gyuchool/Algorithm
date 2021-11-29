#include <string>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> m;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i=0;i<completion.size(); ++i){
        if(m[completion[i]] > 0){
            m[completion[i]]++;
        }
        else{
             m[completion[i]]=1;
        }
      
    }
    
    for(int i=0;i<participant.size();++i){
        if(m[participant[i]] == 0){
            answer=participant[i];
            break;
        }
        else{
            
            m[participant[i]]--;
        }
            
    }
    return answer;
}
