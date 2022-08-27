#include <vector>
#include <queue>
typedef long long int ll;

using namespace std;
queue<int> q1;
queue<int> q2;

int solution(vector<int> queue1, vector<int> queue2) {

    int answer = 0;
    ll a = 0;
    for (int i : queue1) {
        a += i;
        q1.push(i);
    }

    ll b=0;
    for (int i : queue2) {
        b+=i;
        q2.push(i);
    }
    int idx1=0;int idx2=0;
    ll total = (a+b)/2;
    int totalSize = queue1.size() + queue2.size();

    while (a!=b) {
        if ((a + b) % 2 == 1) {
            return -1;
        }
        if (a == 0 || b == 0) {
            return -1;
        }
        if (idx1 >= totalSize || idx2 >= totalSize) {
            return -1;
        }
        if (b > a) {
            int top = q2.front();

            answer++;
            b-=top;
            a+=top;
            if (a == total) {
                break;
            }
            idx2++;
            q2.pop();
            q1.push(top);
        } else if (b < a) {
            int top = q1.front();
            answer++;
            a-=top;
            b+=top;
            if (b == total) {
                break;
            }
            idx1++;
            q1.pop();
            q2.push(top);
        }
    }
    return answer;
}
