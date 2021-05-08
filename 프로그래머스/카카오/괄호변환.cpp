#include <string>
#include <vector>

using namespace std;

//u가 올바른 문자열인지
bool All(string u){
    vector<char> vec;
    vec.push_back('a');
    
     for(int i=0;i<u.length(); ++i){

        if(u[i] == '('){
            vec.push_back(u[i]);
        }
        else if(u[i] == ')'){
                if(vec.back() == '('){
                    vec.pop_back();
                    continue;
                }
                else{
                    vec.push_back(u[i]);
                }
        }
    }
    if(vec.size()==1){
        return true;
    }
    return false;
}
   

string solution(string p) {
    string answer = "";
    string u="";
    int l=0;
    int r=0;
    string v="";
    
    vector<char> vec;
    if(p.length()==0){
        return answer;
    }
    for(int i=0;i<p.length(); ++i){
        
        if(p[i] == '('){
            u+=p[i];
            l++;
        }
        if(p[i]==')'){
            u+=p[i];
            r++;
        }
        if(l!=0 && r!=0 &&l == r){
            v = p.substr(i+1);
            break;
        }
    }
    if(All(u)){
       u += solution(v);
        return u;
    }
    else{
        answer+='(';
        answer+=solution(v);
        answer+=')';
        for(int i=1;i<u.length()-1; ++i){
            if(u[i]==')'){
                answer+='(';
            }
            else{
                answer+=')';
            }
        }
        return answer;
    }
}
