#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
int arr[10001];
int visited[10001];

vector<int> v;
set<vector<int>> st;

void back(int start)
{
	if(v.size() == m)
	{
		st.insert(v);
		return;
	}

	for(int i=start;i<n;i++)
	{
		v.push_back(arr[i]);
		back(i);
		v.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	back(0);
	for (auto value : st)
	{
		for (int value1 : value)
		{
			cout << value1 << ' ';
		}
		cout << endl;
	}
}
