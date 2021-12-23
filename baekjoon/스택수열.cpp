#include <iostream>
#include <vector>
using namespace std;

int info[100001];
int n;
string res="";
vector<int> answer;//info와 비교해서 같으면 

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num = 1;

	cin >> n;
	vector<int> stack;
	
	for (int i = 0; i < n; ++i) {
		cin >> info[i];//만들고 싶은 수열 입력
	}

	
	stack.push_back(num);//시작 1~ 넣어줌
	res += "+\n";
	int index = 0;//찾을 배열의 index

	while (index < n) {
		int peek;
		if (stack.empty()) {
			peek = 0;
			
		}
		else {
			peek = stack.back();
		}
		
		if (info[index] >= peek) {

			if (info[index] == peek) {

				answer.push_back(stack.back());
				
				stack.pop_back();
				
				res += "-\n";//pop해준다 answer에 푸쉬해준다
				index++;
			}
			else {
				stack.push_back(++num);//찾을때까지 푸쉬
				res += "+\n";
			}
		}
		else {
			res = "NO";
			break;
		}
		
	}

	cout << res;

}
