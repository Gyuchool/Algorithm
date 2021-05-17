#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt=0;
    int zero=0;
    while(s!="1"){
        string tmp="";
        for(int i=0;i<s.size(); ++i){ //1만 남기기
            if(s[i]=='1'){
                tmp+=s[i];
            }
            else
                zero++;
        }
        int len = tmp.size(); //길이 
        string ne="";
        while(len!=0){
            int a = len%2;
            ne = ne+to_string(a);
            len/=2;
        }
        s= ne;
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}
