#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int t;
string s;
vector<char> v;

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        stack<char> master;
        stack<char> slave;

        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '<') {
                if (master.empty()) {
                    continue;
                }
                else{
                    char top = master.top();
                    master.pop();
                    slave.push(top);
                }
            } else if (s[j] == '>') {
                if (slave.empty()) {
                    continue;
                } else {
                    char top = slave.top();
                    slave.pop();
                    master.push(top);
                }
            } else if (s[j] == '-') {
                if (!master.empty()) {
                    master.pop();
                }
            } else {
                master.push(s[j]);
            }
        }
        while (!master.empty()) {
            slave.push(master.top());
            master.pop();
        }
        while (!slave.empty()) {
            cout<<slave.top();
            slave.pop();
        }
        cout << endl;
    }
}
