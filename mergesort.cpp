#include <bits/stdc++.h>
using namespace std;

void merge_sort( vector<int> & numbers )
{
	if( numbers.size() <= 1 ) return;
	cout << numbers.size() << endl;
	vector<int> left, right;
	left.insert( left.end(),  numbers.begin() , numbers.begin() + numbers.size()/2 );
	right.insert( right.end(),  numbers.begin() + numbers.size()/2 , numbers.end() );
	merge_sort( left );
	merge_sort( right );
	int l = 0, r = 0;
	while( l + r < numbers.size() )
	{
		if( l < left.size() && r < right.size() )
		{
			if( left[l] > right[r] )
				numbers[l+r] = left[l++];
			else
				numbers[l+r] = right[r++];
		}
		else if( l < left.size() )
			numbers[l+r] = left[l++];
		else
			numbers[l+r] = right[r++];	
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n ; ++i)
		cin >> numbers[i];

	merge_sort(numbers);

	for ( auto p : numbers )
		cout << p << " ";
	cout << endl;


	return 0;
}
