#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0; i<new_id.size(); ++i){
        new_id[i] = tolower(new_id[i]);
    }
    for(int i=0; i<new_id.size(); ++i){
     if(isdigit(new_id[i]) == 0 && new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.' && !('a'<=new_id[i]&&new_id[i]<='z')){//제거
            continue;
        }
        else{
            answer+=new_id[i];
        }
    
    }
     
    
    int size = answer.size();
    string ans="";
    for(int i=0; i<size; ++i){
        if(answer[i] =='.' && answer[i+1]=='.'){
           continue; 
        }
        ans+=answer[i];
    }
    if(ans[0] == '.'){
        ans = ans.substr(1);
    }
    if(ans[ans.size()-1] == '.'){
        ans = ans.substr(0, ans.size()-1);
    }
    if(ans.size() == 0){
        ans = "a";
    }
    if(ans.size()>=16){
        ans = ans.substr(0, 15);
        if(ans[ans.size()-1] == '.'){
            ans = ans.substr(0, ans.size()-1);
        }
    }
    if(ans.size()<=2){
        char tmp = ans[ans.size()-1];
        while(ans.size()!=3){
            ans+=tmp;
        }
    }
    return ans;
}
