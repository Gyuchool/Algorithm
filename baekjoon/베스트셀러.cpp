#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string, int> mp;

int main()
{
	int n;
	string key;

	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> key;
		if(mp.find(key)!=mp.end())
		{
			mp[key] += 1;
		}
		else
		{
			mp.insert({ key, 1 });
		}
	}

	int ma = 0;
	for(auto iter : mp)
	{
		ma = max(iter.second, ma);
	}
	vector<string> v;
	for (auto iter : mp)
	{
		if(iter.second == ma)
		{
			v.push_back(iter.first);
		}
	}
	sort(v.begin(), v.end());
	cout << v[0];
}
