#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; ++i){
        int tmp = arr1[i]|arr2[i];
        string st="";
        while(tmp != 0){
            if(tmp%2==1){
                st="#"+st;
            }
            else{
                st=" "+st;
            }
            tmp/=2;
        }
        if(st.length()!=n){
            int len = n- st.length();
            for(int i=0;i<len; ++i){
                st=" "+st;
            }
        }
        answer.push_back(st);
    }
    return answer;
}
