// Alfredo L!ma 

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

// - Lista de Adjacência :
vector< vector < ii > > List_Adj;

void init_List( int qt_vertex )
{
	List_Adj.clear();
	List_Adj.resize(qt_vertex);
}

void add_Edge_List( int from , int arrival, int w )
{
	List_Adj[from].push_back( ii(arrival,w) );
	// Se o grafo for direcionado comente abaixo:
	List_Adj[arrival].push_back( ii(from,w) );
}

int main(int argc, char const *argv[])
{

	int vertex, edges;
	vertex = 5;
	edges = 5;
	init_List(vertex);
	add_Edge_List(0,1,21);
	add_Edge_List(1,2,8);
	add_Edge_List(1,3,7);
	add_Edge_List(2,3,17);
	add_Edge_List(3,4,31);

	cout << "Representação de Lista de Adjacência: " << endl;
	cout << "Vertice " << "    - Arestas " << endl;
	for (int i = 0; i < vertex ; ++i)
	{
		cout << i << "           - ";
		for (int j = 0; j < List_Adj[i].size() ; ++j)
		{
			cout << " " << List_Adj[i][j].first << " (" << List_Adj[i][j].second << ")";
		}
		cout << endl;
	}
	return 0;
}
