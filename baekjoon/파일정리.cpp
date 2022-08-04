#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int n;
string s[50001];
map<string, int> mp;

vector<string> split(string input, char del) {
    vector<string> answer;
    stringstream ss(input);
    string tmp;

    while (getline(ss, tmp, del)) {
        if (tmp == "" || tmp.empty()) {
            continue;
        }
        answer.push_back(tmp);
    }
    return answer;
}

int main() {
    cin >> n;
    string x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        string ex = split(x, '.')[1];

        mp[ex]++;
    }

    for (const auto &item: mp) {
        cout << item.first << ' ' << item.second << '\n';
    }
}
