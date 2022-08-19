#include <iostream>
#include <set>

using namespace std;

string s;
set<string> st;

int main(){
    cin>>s;

    for (int i = 1; i < s.size(); ++i) {
        for (int j = 0; j <= s.size()-i; j++) {
            st.insert(s.substr(j, i));
        }
    }

    cout<<st.size() + 1;
}
