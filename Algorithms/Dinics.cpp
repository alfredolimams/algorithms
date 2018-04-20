#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)

int graphM[210][210];
vector<set<int>> graph;
int level[210];

bool bfs(int f, int t) {
	memset( level, -1 , sizeof level );
	level[f] = 0;
	queue<int> q;
	q.push(f);
	while (!q.empty()) {
		int v = q.front();	q.pop();
		for (auto u : graph[v])
		  	if (level[u] < 0 && graphM[v][u]){
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
      minFlow -= flow;
      graphM[f][v] -= flow;
      graphM[v][f] += flow;
      maxFlow += flow;
    }
  }
  return maxFlow;
}

int dinics(int f, int t) {
  	int flow_max = 0;
  	int flow;
		do {
			bfs(f, t);
			flow = dfs(f, t, 1 << 20);
			flow_max += flow;
		} while (flow);
  return flow_max;
}

int main(int argc, char const *argv[]) {

  int V, E;
  cin >> V >> E;

  graph.resize(V);
  memset(graphM, 0, sizeof graphM);

  for (int i = 0; i < E; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    graph[u].insert(v);
    graph[v].insert(u);
    graphM[u][v] = c;
  }

  printf("|%d|\n", dinics(0, 5));

  return 0;
}
