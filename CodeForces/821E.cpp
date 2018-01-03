#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define Mod (long long)(1e9 + 7)
typedef vector<long long> vi;
typedef vector< vi > vvi;

int vy = [-1,0,1];

vvi multM ( vvi &m1 , vvi &m2 )
{
	vvi ans;
	ans.resize( m1.size() , vi( m2[0].size() , 0 ) );

	for (long long i = 0; i < m1.size() ; ++i)
			for (long long j = 0; j < m2[0].size() ; ++j)
				for (long long k = 0; k < m1[0].size() ; ++k)
					ans[i][j] = ((m1[i][k] * m2[k][j])%Mod + ans[i][j])%Mod;
	
	return ans;
}

vvi expM ( vvi &m , long long e )
{
	vvi ans;
	vvi temp = m;
	ans.resize( 4, vector<long long>(4,0) );
	for (long long i = 0; i < 4; ++i)
		ans[i][i] = 1;


	while( e )
	{
		if( e&1 )
			ans = multM(ans,temp);
		temp = multM(temp,temp);
		e /= 2;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	vvi matrix;
	matrix.resize( 4, vector<long long>(4,1) );
	for (long long i = 0; i < 4; ++i)
		matrix[i][i] = 0;
	
	long long n;
	cin >> n;

	vvi ans = expM( matrix , n );

	DEBUG for (long long i = 0; i < 4; ++i)
	{
		for (long long j = 0; j < 4; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	DEBUG cout << "---------------" << endl;
	cout << ans[3][3] << endl;
	
	return 0;
}