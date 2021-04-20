#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<char> v;
    int answer = 0;
    int check =1;
    string tmp;
    for(int i=0; i<s.size(); ++i){
        s = s.substr(1)+s[0];
        for( int i=0; i<s.size(); ++i){
            check =0;
            if(s[i]=='(' || s[i] == '{' || s[i] == '['){
                v.push_back(s[i]);
            }
            else{
                if(v.empty()){
                    check = 1;
                    break;
                }
                if(s[i] == ')' && v.back() == '('){
                    v.pop_back();
                }
                else if(s[i] == '}' && v.back() == '{'){
                    v.pop_back();
                }
                else if(s[i] == ']' && v.back() == '['){
                    v.pop_back();
                }
                else{
                    check =1;
                    break;
                }
            }
        }
        if(check==0 && v.empty())answer++;
        
    }
    
    return answer;
}
