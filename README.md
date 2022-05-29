# Algorithm

현재 백준 골드2

- 백준
  실1~ 골드 문제 풀기

- 프로그래머스
  lv.1 카카오문제만
  lv.2 ~ 전부 풀어보기

- 내 블로그
 https://giron.tistory.com/
 
 c++로 stringTokenizer
 ```
#include<iostream>
#include<string>
#include<vector>
#include<sstream> // 이게 중요

using namespace std;

int main()
{
    string str="java c c++ python";
    istringstream ss(str);
    string stringBuffer;
    vector<string> x;
    x.clear();

    //구분자가 , 이라면 getline(ss, stringBuffer, ',')쓰면됨
    while (getline(ss, stringBuffer, ' ')){
        x.push_back(stringBuffer);
    }
    //x에 토큰들 담김
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<endl;
    }
    
    return 0;
}
```

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
