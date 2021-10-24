#include <iostream>
#include <string>
using namespace std;

string s;
int alpha[27];

int main(){
    cin>>s;
    
    for(int i=0; i<s.size(); i++){
        alpha[s[i]-'A']++;
    }
    bool finish =false;
    int cnt=0;
    for(int i=0; i<27; i++){
        if(alpha[i]%2 == 1){
            cnt++;
        }
        if(cnt == 2){
            cout<<"I'm Sorry Hansoo";
            finish=true;
            break;
        }
    }
    if(!finish){
        string front ="";
        string back = "";
        string center ="";
        for(int i='A'-'A'; i<='Z'-'A'; i++){
            
            if(alpha[i]%2 == 1){
                center += (char)('A'+i);
                alpha[i]--;
                
            }
            while(alpha[i] != 0 && alpha[i]%2 == 0){
                front= front + (char)('A'+i);
                back = (char)('A'+i) + back;
                alpha[i]-=2;
            }
            
        }
        cout<<front + center + back;
    }
    
}
