#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define DEBUG1 if(1)
#define MAXV 210

vector< vector<int> > graph[2];
int graphF[2][MAXV][MAXV];

void generateGraph( vector<vector<int>> &m )
{
	int size = m.size();
	memset( graphF, 0 , sizeof graphF );
	for (int i = 0; i < 2 ; ++i)
	{
		graph[i].clear();
		graph[i].resize(MAXV);
	}
	for (int i = 0; i < size ; ++i)
	{
		vector< int > line;
		line.push_back(0);
		for (int j = 0; j < size ; ++j)
			if( !m[i][j] ) line.push_back( i*size + j );
		line.push_back(size*size+1);

		for (int j = 1; j < line.size() ; ++j)
		{
			graph[0][ line[j-1] ].push_back( line[j] );
			graphF[0][ line[j-1] ][ line[j] ] = 1;
		}
	}
	for (int i = 0; i < size ; ++i)
	{
		vector< int > row;
		row.push_back(0);
		for (int j = 0; j < size ; ++j)
			if( !m[j][i] ) row.push_back( i*size + j );
		row.push_back(size*size+1);

		for (int j = 1; j < line.size() ; ++j)
		{
			graph[1][ row[j-1] ].push_back( row[j] );
			graphF[1][ row[j-1] ][ row[j] ] = 1;
		}
	}
}

void print( vector<vector<int>> &m )
{
	printf("#############################\n");
	for (int i = -1; i < int(m.size()) ; ++i)
		printf("%3d|", i+1);
	printf("\n");
	for (int i = 0; i < m.size() ; ++i)
	{
		printf("%3d|", i+1);
		for (int j = 0; j < m[i].size() ; ++j)
		{
			printf("%3d|", m[i][j]);
		}
		printf("\n");
	}
	printf("#############################\n");
}

int Hungaro( vector<vector<int>> &cost )
{
	vector< vector<int> > aux = cost;
	for (int i = 0; i < aux.size() ; ++i)
	{
		int minValue = 1<<20;
		for( int j = 0 ; j < aux.size() ; ++j )
			minValue = min(minValue,aux[j][i]);
		for( int j = 0 ; j < aux.size() ; ++j )
			aux[j][i] -= minValue;
	}
	for (int i = 0; i < aux.size() ; ++i)
	{
		int minValue = 1<<20;
		for( int j = 0 ; j < aux.size() ; ++j )
			minValue = min(minValue,aux[i][j]);
		for( int j = 0 ; j < aux.size() ; ++j )
			aux[i][j] -= minValue;
	}
	DEBUG1 print(aux);
	return 0;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	vector< vector<int> > m;
	m.resize( N, vector<int>(N) );
	for (int i = 0; i < N ; ++i)
	{
		for (int j = 0; j < N ; ++j)
		{
			cin >> m[i][j];
		}
	}

	Hungaro(m);

	return 0;
}