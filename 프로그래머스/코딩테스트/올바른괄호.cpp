#include<string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;


    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        }else{
            if (st.empty()) {
                return false;
            }
            if (st.top() == '(') {
                st.pop();
            }
            else{
                return false;
            }
        }
    }

    return st.empty();
}
