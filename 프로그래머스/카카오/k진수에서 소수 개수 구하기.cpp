#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

string s = "";

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        if (temp == "" || temp.empty()) {
            continue;
        }
        answer.push_back(temp);
    }

    return answer;
}


bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if ((n % i) == 0) {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    s = "";

    while (n) {
        int last = n % k;
        s = to_string(last) + s;
        n = n / k;
    }


    vector<string> v = split(s, '0');
    for (int i = 0; i < v.size(); i++) {
        if (isPrime(stoll(v[i]))) {
            answer++;
        }
    }

    return answer;
}
