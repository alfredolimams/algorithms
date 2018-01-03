#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define DEBUG1 if(1)
#define MAXV 210

vector< vector<int> > graph;
int graphF[MAXV][MAXV];
int level[MAXV];

int generateGraph( vector<vector<int>> &m )
{
	int size = m.size();
	memset( graphF, 0 , sizeof graphF );
	graph.clear();
	graph.resize(MAXV);
	int qt = 0;
	for (int i = 0; i < size ; ++i)
	{
		vector< int > line;
		for (int j = 0; j < size ; ++j)
			if( !m[i][j] ) line.push_back( i*size + j + 1);
		
		for (int j = 1; j < line.size() ; ++j)
		{
			graph[ line[j-1] ].push_back( line[j] );
			graphF[ line[j-1] ][ line[j] ] = 1;
			DEBUG1 printf("Add edge: %d - %d\n", line[j-1], line[j]);
		}
		if( !line.size() ) continue;
		int first = line[0], last = line[ line.size() - 1 ];
		DEBUG1 printf("F: %d e L: %d \n", first, last);
		graph[0].push_back(first);
		graph[first].push_back(0);
		graphF[0][first] = 1;
		graph[size*size+1].push_back(last);
		graph[last].push_back(size*size+1);
		graphF[last][size*size+1] = 1;
		++qt;
	}
	for (int i = 0; i < size ; ++i)
	{
		vector< int > row;
		for (int j = 0; j < size ; ++j)
			if( !m[j][i] ) row.push_back( j*size + i + 1);
		
		for (int j = 1; j < row.size() ; ++j)
		{
			DEBUG1 printf("Add edge: %d - %d\n", row[j-1], row[j]);
			graph[ row[j-1] ].push_back( row[j] );
			graphF[ row[j-1] ][ row[j] ] = 1;
		}
		if( !row.size() ) continue;
		int first = row[0], last = row[ row.size() - 1 ];
		DEBUG1 printf("F: %d e L: %d \n", first, last);
		graph[0].push_back(first);
		graph[first].push_back(0);
		graphF[0][first] = 1;
		graph[size*size+1].push_back(last);
		graph[last].push_back(size*size+1);
		graphF[last][size*size+1] = 1;
		++qt;
	}
	return qt;
}

bool bfs(int f, int t) 
{
	memset( level, -1 , sizeof level );
	level[f] = 0;
	queue<int> q;
	q.push(f);
	while (!q.empty())
	{
		int v = q.front();	q.pop();
		for (auto u : graph[v])
		  	if (level[u] < 0 && graphF[v][u])
			{
	    		level[u] = level[v] + 1;
	    		q.push(u);
	  		}
	}
	return level[t] > 0;
}

int dfs(int f, int t, int minFlow) {
	if (f == t)
		return minFlow;
	int maxFlow = 0;
	for (auto v : graph[f]) {
		if ((level[v] == 1 + level[f]) && (graphF[f][v])) {
			int flow = dfs(v, t, min(minFlow, graphF[f][v]));
			if( !flow ) continue;
			DEBUG1 printf("%d %d -> %d\n", f, v, flow);
			minFlow -= flow;
			graphF[f][v] -= flow;
			graphF[v][f] += flow;
			maxFlow += flow;
		}
	}
  	return maxFlow;
}

int dinics(int f, int t)
{
  	int flow_max = 0;
  	int flow;
  	while (bfs(f, t))	
  		while( (flow = dfs(f, t, 1 << 20)) )
  			flow_max += flow;
  	return flow_max;
}


void print( vector<vector<int>> &m )
{
	printf("#############################\n");
	for (int i = -1; i < int(m.size()) ; ++i)
		printf("%4d|", i+1);
	printf("\n");
	for (int i = 0; i < m.size() ; ++i)
	{
		printf("%4d|", i+1);
		for (int j = 0; j < m[i].size() ; ++j)
		{
			printf("%4d|", m[i][j]);
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
			minValue = min(minValue,aux[i][j]);
		for( int j = 0 ; j < aux.size() ; ++j )
			aux[i][j] -= minValue;
	}
	for (int i = 0; i < aux.size() ; ++i)
	{
		int minValue = 1<<20;
		for( int j = 0 ; j < aux.size() ; ++j )
			minValue = min(minValue,aux[j][i]);
		for( int j = 0 ; j < aux.size() ; ++j )
			aux[j][i] -= minValue;
	}
	print(aux);
	int size = aux.size();
	int v1 = generateGraph(aux);
	int v2 = dinics(0,size*size+1);
	printf("++++\n");
	printf("%d %d\n", v1, v2);
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

	printf("%d\n",Hungaro(m));

	return 0;
}