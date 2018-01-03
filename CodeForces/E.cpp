#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define DEBUG1 if(1)

int graphM[210][210];
int ansM[210][210];

vector<set<int>> graph;
int level[210];

vector< tuple<int,int,int> > flows;

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
		  	if (level[u] < 0 && graphM[v][u])
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
    if ((level[v] == 1 + level[f]) && (graphM[f][v])) {
      int flow = dfs(v, t, min(minFlow, graphM[f][v]));
      if( !flow ) continue;
      minFlow -= flow;
      DEBUG1 printf("%3d %3d = %3d\n", f, v, flow);
      flows.push_back( make_tuple(f,v,flow) );
      graphM[f][v] -= flow;
      graphM[v][f] += flow;
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
  	{
      printf("++++++++++++++++++++++++++++\n");
      while( (flow = dfs(f, t, 1 << 20)) )	flow_max += flow;
  	}
  return flow_max;
}

int main(int argc, char const *argv[]) {

  graph.resize(210);
  int wait_ans = 0;
  int ans_in = 0;
  memset(graphM, 0, sizeof graphM);
  memset(ansM, 0, sizeof ansM);
  int V, E;
  cin >> V >> E;
  int qt;
  vector<int> prev, next, fix;
  fix.resize(V,0);
  for (int i = 0; i < V; ++i)
  {
    cin >> qt;
    prev.push_back(qt);
    ans_in += qt;
    // Change flow in vertex for flow in edge
    graph[0].insert(i+1);
    graph[i+1].insert(0);
    graphM[0][i+1] = qt;
  }
  for (int i = 0; i < V; ++i)
  {
    cin >> qt;
    next.push_back(qt);
    wait_ans += qt;
    // Change flow in vertex for flow in edge
    graph[100].insert(i+1);
    graph[i+1].insert(100);
    graphM[i+1][100] = qt;
    //
    graph[i+1].insert(i+101);
    graph[i+101].insert(i+1);
    graphM[i+101][i+1] = 1<<20;
  }
  int u, v;
  for (int i = 0; i < E ; ++i)
  {
    cin >> u >> v;
    // In
    for( int j = 0 ; j < 2 ; ++j )
    {
      graph[u].insert(100+v);
      graph[100+v].insert(u);
      graphM[u][100+v] = 1<<20;
      swap(u,v);  
    }
  }

  int maxFlow = dinics(0,100);

  vector<int> values;
  for (int i = 0; i <= V ; ++i)
  {
    values.push_back(i);
    values.push_back(100+i);
  }
  sort( values.begin(), values.end() );
  values.push_back(100);
  if( ans_in != wait_ans ) cout << "NO" << endl;
  else if( wait_ans != maxFlow ) cout << "NO" << endl;
  else
  {
    cout << "YES" << endl;
    DEBUG1 printf("#####################################################################\n");
    //sort( flows.begin() , flows.end() );
    for( auto flow : flows ){
      int u = get<0>(flow) , v = get<1>(flow), f = get<2>(flow);
      DEBUG1 printf("### %3d %3d -> %3d\n", u,v,f);
      if( v > 100 ){
        ansM[ v-100 ][ u ] += f;
      }   
    }
    DEBUG1 printf("#####################################################################\n");
    for (int i = 1; i <= V ; ++i)
    {
      int sum = 0;
      for (int j = 1; j <= V ; ++j)
      {
        sum += ansM[j][i];
      }
      ansM[i][i] = prev[i-1] - sum;
    }

    for (int i = 1; i <= V ; ++i)
    {
      for (int j = 1; j <= V ; ++j){
        if( j-1 ) cout << " ";
        printf("%d", ansM[j][i]);
      }
      cout << endl;
    }

  }

  return 0;
}