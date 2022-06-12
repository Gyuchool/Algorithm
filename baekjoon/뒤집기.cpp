#include <iostream>

using namespace std;
string s;

int main(){
	cin >> s;

	int reverse = 0;
	for(int i=0;i < s.size()-1; i++)
	{
		if(s[i] != s[i+1])
		{
			reverse++;
		}

	}
	cout << (reverse + 1) / 2;

}
