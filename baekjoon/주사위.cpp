#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

vector<ll> v;

int main()
{
	ll n, m;
	cin >> n;
	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if(n==1)
	{
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);
		v.push_back(f);
		
	}
	else
	{
		ll mm = min(a + b + c, min(a + b + d, min(b + f + c, min(b + f + d, min(e + f + c, min(e + f + d, min(e + a + c, e + a + d)))))));
		if (mm == a + b + c)
		{
			v.push_back(a);
			v.push_back(b);
			v.push_back(c);
		}
		else if (mm == a + b + d)
		{
			v.push_back(a);
			v.push_back(b);
			v.push_back(d);
		}
		else if (mm == b + f + c)
		{
			v.push_back(f);
			v.push_back(b);
			v.push_back(c);
		}
		else if (mm == f + b + d)
		{
			v.push_back(f);
			v.push_back(b);
			v.push_back(d);
		}
		else if (mm == e + f + d)
		{
			v.push_back(e);
			v.push_back(f);
			v.push_back(d);
		}
		else if (mm == e + f + c)
		{
			v.push_back(e);
			v.push_back(f);
			v.push_back(c);
		}
		else if (mm == a + e + d)
		{
			v.push_back(a);
			v.push_back(e);
			v.push_back(d);
		}
		else if (mm == a + e + c)
		{
			v.push_back(a);
			v.push_back(e);
			v.push_back(c);
		}
	}
	
	sort(v.begin(), v.end());


	if(n == 1)
	{
		cout << v[0] + v[1] + v[2] + v[3] + v[4];
	}
	else
	{
		cout << ((v[0] + v[1] + v[2]) + (v[0] + v[1]) * (n - 1) + v[0] * (n - 2) + (v[0] + v[1]) * (n - 2)) * 4 + v[0] * (n - 2) * (n - 2)*5;
	}
}
