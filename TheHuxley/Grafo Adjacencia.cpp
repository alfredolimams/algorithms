// Alfredo L!ma 

#include <bits/stdc++.h>
using namespace std;


// Representação de grafos sem peso


vector< vector < int > > Matrix_Adj;

// - Lista de Adjacência :

vector< vector < int > > List_Adj;

void init_List( int qt_vertex )
{
	List_Adj.clear();
	List_Adj.resize(qt_vertex);
}

void add_Edge_List( int from , int arrival )
{
	List_Adj[from].push_back( arrival );
	// Se o grafo for direcionado comente abaixo:
	List_Adj[arrival].push_back( from );
}

int main(int argc, char const *argv[])
{

	int vertex, edges;
	vertex = 5;
	edges = 5;
	init_List(vertex);
	// Add aresta 0 - 1
	add_Edge_List(0,1);
	// Add aresta 1 - 2
	add_Edge_List(1,2);
	// Add aresta 1 - 3
	add_Edge_List(1,3);
	// Add aresta 2 - 3
	add_Edge_List(2,3);
	// Add aresta 3 - 4
	add_Edge_List(3,4);

	cout << "Representação de Lista de Adjacência: " << endl;
	cout << "Vertice " << "    - Arestas " << endl;
	for (int i = 0; i < vertex ; ++i)
	{
		cout << i << "           - ";
		for (int j = 0; j < List_Adj[i].size() ; ++j)
		{
			cout << " " << List_Adj[i][j];
		}
		cout << endl;
	}
	return 0;
}