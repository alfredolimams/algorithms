#include <bits/stdc++.h>
using namespace std;

void insertion_sort( vector<int> & numbers )
{
	for (int i = 1; i < numbers.size() ; ++i)
		for (int j = i; j > 0 && numbers[j-1] > numbers[j] ; --j)
			swap( numbers[j-1] , numbers[j] );
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n ; ++i)
		cin >> numbers[i];

	insertion_sort(numbers);

	for ( auto p : numbers )
		cout << p << " ";
	cout << endl;

	return 0;
}
