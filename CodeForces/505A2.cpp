#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)

int minChange( string &s )
{
	int ans = 0;

	for (int i = 0; i < s.size()/2 ; ++i)
		if( s[i] != s[s.size()-i-1] )
			ans++;

	return ans;
}


int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	string aux1, aux2;
	vector< int > idxs;

	for (int i = 0; i <= s.size() ; ++i)
	{
		string temp;
		for( int j = 0; j < i ; ++j )
		{
			temp += s[j]; 
		}
		temp += "X";
		for( int j = i; j < s.size() ; ++j )
		{
			temp += s[j]; 
		}
		DEBUG cout << temp << endl;
		if( minChange(temp) == 1 ){
			DEBUG cout << "Entrou" << endl;
			if( temp[i] != temp[temp.size()-1-i] )
			{
				temp[i] = temp[temp.size()-1-i];
				cout << temp << endl;
				return 0;
			}
		}
	}
	cout << "NA" << endl;
	return 0;
}