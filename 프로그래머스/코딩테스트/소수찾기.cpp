#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
bool visited[8];
vector<bool>primeNums;
vector<int> combined;

vector<bool> makePrimePool(string numbers) {
    int digit = pow(10, numbers.length());
    vector<bool> primeNum(digit, true);
    fill(primeNum.begin(), primeNum.begin() + 2, false);
    for (int i = 2; i < digit; i++) {
        if (primeNum[i] == false) continue;
        for (int j = i * 2; j < digit; j += i) {
            primeNum[j] = false;
        }
    }
    return primeNum;
}
bool prime(int n) {
    if (n == 0 || n == 1)return false;
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0)return false;
    }
    return true;
}

void permutation(int depth, string numbers, string res) {

    if (depth == numbers.length())
        return;
    for (int i = 0; i < numbers.length(); i++) {
        if (!visited[i]) {
            string currNum = res + numbers[i];
            visited[i] = true;
            if (primeNums[atoi(currNum.c_str())])
                combined.push_back(atoi(currNum.c_str()));
            permutation(depth+1, numbers, res + numbers[i]);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {

    primeNums = makePrimePool(numbers);
    permutation(0, numbers, "");

    //중복제거
    sort(combined.begin(), combined.end());
    combined.erase(unique(combined.begin(), combined.end()), combined.end());

    return combined.size();
}
