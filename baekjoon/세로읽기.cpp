#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s[5];

int main(){
    int ma =0;

    for (int i = 0; i < 5; ++i) {
        cin>>s[i];
        if (ma < s[i].size()) {
            ma = s[i].size();
        }
    }

    for (int i = 0; i < ma; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(s[j][i] == '\0') {
                continue;
            }
            cout<<s[j][i];
        }
    }
}
