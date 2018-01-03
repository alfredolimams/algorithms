#include <bits/stdc++.h>
using namespace std;

#define DB if(1)
#define all(x) x.begin(),x.end()

int n, s;
multiset<int> values;

int c[3];
int k[3];

vector<int> can[3];


int gcd( int a , int b )
{
	while( b ){
		int t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int cost()
{
	int ans = 0;
	for (int i = 0; i < 1; ++i)
		ans += abs(c[i]*k[i]-c[i+1]*k[i+1]);
	return ans;
}

bool isValid()
{
	int sum = 0;
	for (int i = 0; i < 3; ++i)
		sum += c[i]*k[i];
	return sum == s;
}

void generation( int id, int v )
{
	if( (s-v*c[id])%gcd(c[(id+1)%3],c[(id+2)%3]) ) return;
	can[id].push_back(v);
}

int main(int argc, char const *argv[])
{
	cin >> n >> s;
	int v;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> v;
		values.insert(v);
	}

	for (int i = 0; i < 3; ++i)
		c[i] = values.count(3+i);

	for (int i = 0; i <= s; ++i)
	{
		generation(0,i);
		generation(1,i);
		generation(2,i);
	}

	DB
	{
		for( auto v : can[0] )
			cout << v << " ";
		cout << endl;
		for( auto v : can[1] )
			cout << v << " ";
		cout << endl;
		for( auto v : can[2] )
			cout << v << " ";
		cout << endl;
	}

	for( auto v : can[1] )
	{
		int idx1 = lower_bound(all(can[0]),v) - can[0].begin();
		cout << v << " - " << can[0][idx1] << endl;
		for (int i = 0; i <= idx1; ++i)
		{
			
		}
	}

	return 0;
}