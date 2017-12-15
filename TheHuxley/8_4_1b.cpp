#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f
#define fi first
#define se second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef tuple<int,int,int> iii;

vvi AdjList;
vi vstd;

void init( int vertex )
{
	vstd.clear();
	AdjList.clear();
	vstd.resize(vertex,-1);
	AdjList.resize(vertex);
}

int dfs( int from, int arrival )
{
	vstd[from] = 0;
	for ( auto v : AdjList[from] )
	{
		if( v == arrival ) ++vstd[from];
		else if( vstd[v] != -1 ) vstd[from] += vstd[v];
		else vstd[from] += dfs(v, arrival);
	}
	return vstd[from];
}

int main()
{
	int vertices, passos;
	cin >> vertices;
	int saida , chegada;
	cin >> saida >> chegada;
	init(vertices);
	vvi graph = vvi(vertices);
	for( int i = 0 ; i < vertices ; ++i ) graph[i].resize(vertices);
	for (int i = 0; i < vertices ; ++i)
		for (int j = 0; j < vertices; ++j)
			cin >> graph[i][j];
	for (int i = 0; i < vertices ; ++i)
		for (int j = 0; j < vertices; ++j)
				if( graph[i][j] )
					AdjList[ i ].pb( j );
	cout << dfs( saida , chegada ) << endl;
	return 0;
}
