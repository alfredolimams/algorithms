#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define DEBUG if(0)

long long fexp( long long b , long long e )
{
	long long exp = 1LL; 
	while( e )
	{
		if( e&1 ) exp = (exp*b)%mod;
		b = (b*b)%mod;
		e = e/2LL;	
	}
	return exp;
}

int main(int argc, char const *argv[])
{
	long long sum_digits = 0, sum_words = 0;
	string s, ss;
	cin >> s;
	long long k;
	cin >> k;

	for (int i = 0 ; i < s.size() ; ++i)
		if( s[i] == '0' || s[i] == '5' )
			sum_digits = (sum_digits + fexp(2,i))%mod;

	DEBUG cout << "Dig " << sum_digits << endl;

	long long e = fexp(2,s.size()) - 1LL;

	long long inv = fexp( e , mod - 2LL );

	long long v = fexp( 2 , k*s.size() ) - 1LL;

	cout << (((sum_digits*inv)%mod)*v)%mod << endl;

	return 0;
}