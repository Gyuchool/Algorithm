#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> stack;

void Combination(string arr, vector<char> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        sort(comb.begin(), comb.end());
        string t = "";
        for (int i = 0; i < comb.size(); i++)
            t += comb[i];
            
        stack.push_back(t);
    }
    else if (depth == arr.size())  // depth == n // 계속 안뽑다가 r 개를 채우지 못한 경우는 이 곳에 걸려야 한다.
    {
        return;
    }
    else
    {
        // arr[depth] 를 뽑은 경우
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);

        // arr[depth] 를 뽑지 않은 경우
        Combination(arr, comb, r, index, depth + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < course.size(); ++i) {
        stack.clear();
        
        for (int j = 0; j < orders.size(); j++) {
            vector<char> tmp(course[i]);

            Combination(orders[j], tmp, course[i], 0, 0);
        }
        int ma = 0;
        map<string, int> dic;

        for (int k = 0; k < stack.size(); k++) {
            if (dic[stack[k]]) {
                dic[stack[k]]++;
                if (ma < dic[stack[k]]) {
                    ma = dic[stack[k]];
                }
            }
            else {
                dic[stack[k]] = 1;
            }
        }

        for (auto it = dic.begin(); it != dic.end(); it++) {
            if (it->second == ma) {
                answer.push_back(it->first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
