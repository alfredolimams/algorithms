#include <bits/stdc++.h>
using namespace std;

#define mod %1000000007
#define DEBUG if(0)

long long fexp( long long b , long long e )
{
	long long exp = 1LL; 
	while( e )
	{
		if( e&1 ) exp = (exp*b)mod;
		b = (b*b)mod;
		e = e/2LL;	
	}
	return exp;
}
int main(int argc, char const *argv[])
{
	long long ans = 0;
	string s, ss;
	cin >> s;
	long long k;
	cin >> k;
	vector< long long > values;
	for (int i = 0 ; i < s.size() ; ++i)
		if( s[i] == '0' || s[i] == '5' )
			values.push_back(i);

	long long e = fexp(2, s.size() );
	long long temp = 1LL;
	long long sum_e = 0LL;
	for (int i = 0; i < k ; ++i)
	{
		sum_e = (sum_e + temp)mod;
		temp = (temp*e)mod;
	}

	DEBUG cout << sum_e << " ----" << endl;

	for (int i = 0; i < values.size() ; ++i)
	{
		long long ans_temp = (fexp(2, values[i])*sum_e)mod;
		ans = (ans + ans_temp)mod;
	}

	cout << ans << endl;

	return 0;
}