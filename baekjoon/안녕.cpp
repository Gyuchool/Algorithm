#include <iostream>
#include <algorithm>
using namespace std;

int n;
int l[21]; //체력
int j[21];	//기쁨
int dp[21][101];

int go(int start, int power)
{
	if (start == n)
	{
		return 0;
	}
	if (dp[start][power])
	{
		return dp[start][power];
	}

	int Get = 0;
	if (power - l[start] > 0)
	{
		Get = j[start] + go(start + 1, power - l[start]);
	}
	int notGet = go(start + 1, power);

	return dp[start][power] = max(notGet, Get);

}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> l[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> j[i];
	}

	cout << go(0, 100);
}
