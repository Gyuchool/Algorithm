#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<string> v;
    for(int i=0; i<skill_trees.size(); ++i){
        string tmp = skill_trees[i];
        int index=0;
        int out=0;
        for(int j=0; j<tmp.size(); ++j){
            if(skill[index] == tmp[j]){
                index++;
                continue;
            }
            else{
                for(int k=0;k<skill.size(); ++k){
                    if(skill[k] == tmp[j]){
                        out = 1;
                        break;
                    }
                }
            }
            if(out == 1){
               break;
            }
        }
        if(!out)
            answer++;
    }
    
    return answer;
}
