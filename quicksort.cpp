#include <bits/stdc++.h>
using namespace std;

int partition( vector<int> & a , int b , int e )
{
	int p = b;
	for (int i = b; i < e ; ++i)
		if( a[i] <= a[e] )
		{
			swap(a[p++],a[i]);
		}
	swap(a[p],a[e]);
	return p;
}

void quicksort( vector<int> & a , int b , int e )
{
	if( b < e )
	{
		int p = partition(a,b,e);
		quicksort(a,b,p-1);
		quicksort(a,p+1,e);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	srand( time(NULL) );
	n = rand()%1000;
	++n;
	vector<int> a;
	n = 10;
	for (int i = 0; i < n; ++i)
		a.push_back( rand()%10 );

	for( auto p : a )
		cout << p << " ";
	cout << endl;

	quicksort(a,0,n-1);

	for( auto p : a )
		cout << p << " ";
	cout << endl;
	return 0;
}
