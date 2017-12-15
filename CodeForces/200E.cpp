#include <bits/stdc++.h>
using namespace std;

int n, s;
multiset<int> values;

int c[3];
int k[3];



int cost()
{
	int ans = 0;
	for (int i = 0; i < 1; ++i)
		ans += abs(c[i]*k[i]-c[i+1]*k[i+1]);
	return ans;
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
	return 0;
}