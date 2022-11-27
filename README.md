# Algorithm

 c++로 stringTokenizer
```c++
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
```
next_permutation을 이용한 조합
```c++
vector<int> v{1,2,3,4}; // 조합 출력할 원소들
vector<int> c{0,0,1,1}; // 4개중 2개를 뽑을 벡터리스트 (순서 중요)

do{
        for(int i =0; i<v.size();i++) {
                if(c[i]==1)cout<<v[i]<<' '; 
        }
        cout<<endl; 
}while(next_permutation(c.begin(),c.end()));

//출력결과
3 4 
2 4 
2 3 
1 4 
1 3 
1 2 

// prev_permu..를 이용한 조합
vector<int> v{1,2,3,4};
vector<int> c{1,1,0,0}; // 4개중 2개를 뽑을 벡터리스트 (순서 중요)

do{
      for(int i =0; i<v.size();i++) {
              if(c[i]==1)cout<<v[i]<<' '; 
      }
      cout<<endl; 
}while(prev_permutation(c.begin(),c.end()));

//출력결과
1 2 
1 3 
1 4 
2 3 
2 4 
3 4 
```
nPr
```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = { 1, 2, 3, 4, 5 };

	int n = v.size();  // 5
	int r = 2;

	do
	{
		for (int i = 0; i < r; i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
		reverse(v.begin() + r, v.end());

	} while (next_permutation(v.begin(), v.end()));
}
```
