## 순열과 조합 정리
https://github.com/Gyuchool/Algorithm/blob/master/formula/%EC%88%9C%EC%97%B4%EA%B3%BC%20%EC%A1%B0%ED%95%A9.md

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
int index;
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
	
	go(0, 1);
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
![image](https://user-images.githubusercontent.com/60054318/140243412-3b9943af-9819-423d-a2d1-bf21ff3cf341.png){: width="100" height="100"}

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
