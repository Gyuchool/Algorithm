#include <iostream>
#include <string>
using namespace std;

string s;
int l = 0;
int r;
int flag = 0;
int tmp_l, tmp_r;

int check(int l, int r) {
    flag = 0;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
            continue;
        }
        else {
            if(flag == 0 && s[l+1] == s[r]){
                tmp_l = l;
                tmp_r = r;
                l++;
                flag = 3;
                continue;
            }
            else if(flag == 0 && s[l] == s[r-1]){
                r--;
                flag = 1;
                continue;
            }
            else{
                if(flag == 3){
                    l=tmp_l;
                    r = tmp_r-1;
                    flag=1;
                }
                else{
                    flag = 2;
                    break;
                }
            }
        }
    }
    if(flag == 1 || flag == 3){
        return 1;
    }
    else if(flag == 2){
        return 2;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << check(0, s.size()-1) << endl;
        
    }
}
