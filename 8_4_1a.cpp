#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF INT_MAX/10
#define pb push_back
#define DEG_to_RAD(x) (x/180.0)*M_PI
#define RAD_to_DEG(x) (x*180.0)/M_PI
#define DEBUG if(1)
#define MIN_to_DEG(x) x/60.0

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class Matrix
{
public:
	int line, collumn;
	vector< vector<double> > matrix;
	Matrix()
	{
		line = collumn = 0;
	}
	Matrix( int l, int c )
	{
		line = l;
		collumn = c;
		matrix.resize(l);
		for( int i = 0 ; i < line ; ++i )
			matrix[i].resize( c, (double)0 );
	}
	Matrix operator * ( Matrix other )
	{
		if( collumn != other.line )
			return Matrix();
		Matrix r = Matrix( line, other.collumn );
		for (int i = 0; i < line ; ++i)
			for (int j = 0; j < other.collumn ; ++j)
				for (int k = 0; k < collumn ; ++k)
					r.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
		return r; 
	}
	Matrix operator + ( Matrix other )
	{
		if( collumn != other.collumn || line != other.line )
			return Matrix();
		Matrix r = Matrix( line, collumn );
		for (int i = 0; i < line ; ++i)
			for (int j = 0; j < collumn ; ++j )
				r.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		return r;
	}
	void print()
	{
		for (int i = 0; i < line ; ++i)
		{
			for (int j = 0; j < collumn ; ++j)
			{
				if(j) printf(" ");
				printf("%.3lf", matrix[i][j] );
			}
			printf("\n");
		}
	}
	Matrix exp_matrix( int e )
	{
		if( e == 1 )
			return *this;
		else
		{
			Matrix r = exp_matrix( e>>1 );
			if( e&1 )
				return (*this)*r*r;
			return r*r;
		}
	}
	Matrix identidy( int n )
	{
		Matrix r = Matrix( n, n );
		for (int i = 0; i < n ; ++i)
			r.matrix[i][i] = 1.0;
		return r;
	}
	Matrix transposta()
	{
		Matrix r = Matrix( collumn, line );
		for (int i = 0; i < line ; ++i)
			for (int j = 0; j < collumn ; ++j)
				r.matrix[j][i] = matrix[i][j];
	}
};
int main()
{
	int vertices, passos;
	cin >> vertices >> passos;
	int saida , chegada;
	cin >> saida >> chegada;
	Matrix graph = Matrix( vertices , vertices );
	for (int i = 0; i < vertices ; ++i)
		for (int j = 0; j < vertices; ++j)
			cin >> graph.matrix[i][j];
	cout << graph.exp_matrix( passos ).matrix[saida][chegada] << endl;
	return 0;
}
