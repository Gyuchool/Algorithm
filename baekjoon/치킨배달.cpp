#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> v;
vector<pair<int, int>> p;

int answer = 99999999;
int visited[51][51];

int getDistance(pair<int, int> h, pair<int, int> c)
{
	return abs(h.first - c.first) + abs(h.second - c.second);
}
void go(int cnt)
{
	if(m == chicken.size())
	{
		int result = 0;
		for(int i=0;i<home.size(); i++)
		{
			int mi = 99999999;
			for(int j=0;j<chicken.size(); j++)
			{
				mi = min(mi, getDistance(home[i], chicken[j]));
			}
			result += mi;
		}
		answer = min(answer, result);
		return;
	}
	
	
	for(int i= cnt;i<p.size(); i++)
	{
		int x = p[i].first;
		int y = p[i].second;
		if(!visited[x][y])
		{
			visited[x][y] = 1;
			chicken.push_back({ x,y });
			go(i+1);
			visited[x][y] = 0;
			chicken.pop_back();
		}
	}
	
}
int main()
{
	cin >> n >> m;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 1)
			{
				home.push_back({ i,j });
			}
			else if(arr[i][j] == 2)
			{
				p.push_back({ i,j });
			}
		}
	}

	go(0);
	cout << answer;

}
