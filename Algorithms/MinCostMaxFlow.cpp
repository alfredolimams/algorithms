#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define DEBUG1 if(1)
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
int graphR[210][210];
int graphC[210][210];
int level[210];
vector<vector<int>> graph;
vector< ii > edges;
unordered_map< int , unordered_map<int , int> > cost;

void CostNetwork()
{
	memset( graphC, 0 , sizeof graphC );
	for ( auto edge : edges )
	{
		int u = edge.first, v = edge.second;
		if( graphR[u][v] ){
			graphC[u][v] = cost[u][v];
		}
		else if( graphR[u][v] ){
			graphC[u][v] = -cost[u][v];	
		}
	}
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
		  	if (level[u] < 0 && graphR[v][u])
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
		if ((level[v] == 1 + level[f]) && (graphR[f][v])) {
			int flow = dfs(v, t, min(minFlow, graphR[f][v]));
			if( !flow ) continue;
			minFlow -= flow;
			graphR[f][v] -= flow;
			graphR[v][f] += flow;
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



int MinCost(int s, int t)
{
	int maxFlow = dinics(s,t);
	int negativeCycle = false;
	do
	{
		CostNetwork();

	} while( negativeCycle );
}

int main(int argc, char const *argv[])
{
	int V, E;
	cin >> V >> E;
	graph.resize(210);
	int u, v, f, c;
	for (int i = 0; i < E ; ++i)
	{
		cin >> u >> v >> f >> c;
		graph[u].push_back( v );
		graph[v].push_back( u );
		edges.push_back( {u,v} );
		edges.push_back( {v,u} );
		graphR[u][v] = f;
		cost[u][v] = c;
		cost[v][u] = c;
	}
	return 0;
}