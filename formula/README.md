## 순열과 조합 정리
https://github.com/Gyuchool/Algorithm/blob/master/formula/%EC%88%9C%EC%97%B4%EA%B3%BC%20%EC%A1%B0%ED%95%A9.md

### #define n, r : n개 중에서 r개 선택

- int arr 대신에 string 을 이용해도 된다. 
- 재귀 들어갈때 combination(string+value)

```
// 중복조합 A, AA, AAEE, AAAAA, AEAEE etc..
char dir[] = { 'A','E','I','O','U' };
vector<string> tmp;

void duplicatePermutation(int depth, int x, string res) {
    if (depth == x) {
        tmp.push_back(res);
        return;
    }

    for (int i = 0; i < 5; i++) {
        duplicatePermutation(depth + 1,x, res+dir[i]); //이렇게하면 string붙이고 pop_back()보다 5ms가량 더 빠름
    }
}


int solution(string word) {
    //1 개일떄 중복, 2개일떄 중복 ,3개일때 .. 5개일떄 중복조합 전부
    for (int i = 1; i <= 5; i++) {
        duplicatePermutation(0, i,"");
    }
}
```
# 순열

## (순서O, 중복X) nPr

```
int arr[r]; // r개 배열 초기화
bool check[n + 1]; // 초기화 

void permutation(int depth){
    if(depth == r){
        for(int i=0;i<r;i++){
          cout<<arr[i]<<' ';
        }
        return;        
    }
    
    for(int i = 1; i <= n; i++){ // 1부터 n개까지 반복
        if(!check[i]){  //방문 안했다면(검사 안했다면)
            check[i] = true;
            arr[depth] = i;
            permutation(depth + 1);
            check[i] = false;
        }
    }
}

int main(void){
    permutation(0);
    return 0;
}
```

## 중복 순열
## (순서O, 중복X) nPr
```
void duplicatePermutation(int depth){
    if(depth == r){
        for(int i=0;i<r;i++){
          cout<<arr[i]<<' ';
        }
        return;        
    }
    
    for(int i = 1; i <= n; i++){
        arr[depth] = i;
        duplicatePermutation(depth + 1);
    }
}

int main(void){
    duplicatePermutation(0);
    return 0;
}
```

# 조합

## (순서X, 중복X) nCr
```
void combination(int depth, int next){
     if(depth == r){
        for(int i=0;i<r;i++){
          cout<<arr[i]<<' ';
        }
        return;        
    }

    for(int i = next; i <= n; i++){ //i 시작이 next주목
        arr[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main(void){

    combination(0, 1);
    return 0;
}
```

## 중복조합

```
void duplicateCombination(int depth, int next){
     if(depth == r){
        for(int i=0;i<r;i++){
          cout<<arr[i]<<' ';
        }
        return;        
    }

    for(int i = next; i <= n; i++){
        arr[depth] = i;
        duplicateCombination(depth + 1, i);
    }
}

int main(void){
    duplicateCombination(0, 1);

    return 0;
}
```

# 백트래킹 정리
 - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 - 고른 수열은 오름차순이어야 한다.

## 문제

![image](https://user-images.githubusercontent.com/60054318/140242321-6a99ef44-aff2-411f-9159-d565cd696344.png)
## 소스코드
```
#include <iostream>
using namespace std;

int n,m;
int arr[9];
int visited[9];
void go(int cnt, int num) {
	if (cnt == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; ++i) {
		if (!visited[i]) {
			visited[i] = 1;
			arr[cnt] = i;
			go(cnt+1, i +1);
			visited[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	//nCm  
	go(0, 1); //1 부터 시작~ 
}

// 중복 허용일땐
for (int i = 1; i <= n; ++i) {
		if (!visited[cnt]) {
			visited[cnt] = 1;
			arr[cnt] = i;
			go(cnt+1);
			visited[cnt] = 0;
		}
}
```
## 문제
![image](https://user-images.githubusercontent.com/60054318/140243022-b645c5f3-2884-4719-b2b9-b7ebcdd3234b.png)
## 소스코드
```
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int arr[9];
int visited[10001];
int n, m;
vector<int> v;

set<vector<int>> check;

void go(int cnt) {
	if (cnt == m) {
		
		check.insert(v);
		
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(arr[i]);
			go(cnt + 1);
			v.pop_back();
			visited[i] = 0;

		}
	}
	
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	go(0);
  
  //set안의 수열들 출력
	for (auto it = check.begin(); it != check.end(); ++it) {
		v = *it;
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}

}
```
## 문제
![image](https://user-images.githubusercontent.com/60054318/140243412-3b9943af-9819-423d-a2d1-bf21ff3cf341.png)

## 소스코드
```
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
int arr[8];
int visited[8];
vector<int> v;
set<vector<int>> st;

void start(int depth) {
	if (m == v.size()) {

		if (st.find(v) != st.end()) { //찾으면
			return;
		}
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] > v[i + 1])
				return;
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout<<'\n';
		st.insert(v);
		return;
	}

	for (int i = depth; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(arr[i]);
			start(depth + 1);
			v.pop_back();
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	start(0);
}
```
