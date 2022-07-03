#include <iostream>
using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;
	int value = c - b;
	if(value<=0)
	{
		cout << -1;
	}
	else
	{
		cout << a / value +1;
	}
}
