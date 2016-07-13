// Alfredo L!ma 

#include <bits/stdc++.h>
using namespace std;

// Representação de grafos sem peso
// - Matriz de Adjacência :

vector< vector < int > > Matrix_Adj;

void init_Matrix( int qt_vertex )
{
	Matrix_Adj.clear();
	Matrix_Adj.resize(qt_vertex);
	for (int i = 0; i < qt_vertex ; ++i)
	{
		Matrix_Adj[i].resize(qt_vertex,0);
	}
}

void add_Edge_Matrix( int from , int arrival )
{
	Matrix_Adj[from][arrival] = 1;
	// Se o grafo for direcionado comente abaixo:
	Matrix_Adj[arrival][from] = 1;
}

int main(int argc, char const *argv[])
{

	int vertex, edges;
	vertex = 5;
	edges = 5;
	init_Matrix(vertex);
	// Add aresta 0 - 1
	add_Edge_Matrix(0,1);
	// Add aresta 1 - 2
	add_Edge_Matrix(1,2);
	// Add aresta 1 - 3
	add_Edge_Matrix(1,3);
	// Add aresta 2 - 3
	add_Edge_Matrix(2,3);
	// Add aresta 3 - 4
	add_Edge_Matrix(3,4);

	cout << "Representação de Matriz de Adjacência: " << endl;
	cout << "-";
	for (int i = 0; i < vertex ; ++i)
	{
		cout << " " << i;
	}
	
	for (int i = 0; i < vertex ; ++i)
	{
		cout << endl << i << " ";
		for (int j = 0; j < vertex ; ++j)
		{
			cout << Matrix_Adj[i][j] << " ";
		}
	}
	cout << endl;
	return 0;
}