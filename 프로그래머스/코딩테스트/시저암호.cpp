#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.size(); i++){
        if(s[i]>='a' && s[i] <='z'){
            if(s[i]+n >'z'){
                s[i] = (s[i] + n - 'a')%26+'a';
                
            }
            else{
                s[i]+=n;
            }
        }
        else if(s[i] >='A' && s[i] <='Z'){
            if(s[i]+n>'Z'){
                s[i] = (s[i] + n - 'A')%26+'A';
            }
            else{
                s[i]+=n;
            }
        }
    }
    
    return s;
}
