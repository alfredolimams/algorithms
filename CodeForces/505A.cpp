#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)


bool isPalidromo( string &s )
{
	int idx1 = 0 , idx2 = s.size() - 1;
	while( idx1 <= idx2 )
	{
		if( s[idx1] != s[idx2] )
			return false;
		idx1++;
		idx2--;
	}
	return true;
}


int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	if( isPalidromo(s) )
	{
		for (int i = 0; i < s.size()/2 ; ++i)
			cout << s[i];

		for (int i = 0; i < 1 + (s.size()&1) ; ++i)
			cout << s[ s.size()/2 ];

		for (int i = s.size()/2 - 1; i >= 0 ; --i)
			cout << s[i];
		cout << endl;
	}
	else
	{
		if( s.size()&1 )
		{
			string temp;
			for
		}
		else
		{

		}
	}
	return 0;
}