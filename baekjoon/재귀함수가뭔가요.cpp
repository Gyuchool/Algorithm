#include <iostream>
#include <algorithm>

using namespace std;

int n;
string prefix = "____";

string s1 = "\"재귀함수가 뭔가요?\"";
string s2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string s3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string s4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";

string ans = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
string answer = "라고 답변하였지.";
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
    string tmp = "";
    for (int i = 0; i < n; ++i) {
        tmp="";
        for (int j = 0; j < i; ++j) {
            tmp+=prefix;
        }
        cout<< tmp + s1<<endl;
        cout<< tmp + s2<<endl;
        cout<< tmp + s3<<endl;
        cout<< tmp + s4<<endl;
    }
    tmp+="____";
    cout<<tmp+"\"재귀함수가 뭔가요?\""<<endl;
    cout<<tmp+ans<<endl;
    cout<<tmp+answer<<endl;
    for (int i = n-1; i >=0; --i) {
        tmp="";
        for (int j = 0; j < i; ++j) {
            tmp+=prefix;
        }
        cout<< tmp + answer<<endl;
    }
}
