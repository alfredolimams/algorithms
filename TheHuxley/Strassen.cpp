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
	Matrix operator - ( Matrix other )
	{
		if( collumn != other.collumn || line != other.line )
			return Matrix();
		Matrix r = Matrix( line, collumn );
		for (int i = 0; i < line ; ++i)
			for (int j = 0; j < collumn ; ++j )
				r.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		return r;
	}
	void print()
	{
		for (int i = 0; i < line ; ++i)
		{
			for (int j = 0; j < collumn ; ++j)
			{
				if(j) printf(" ");
				printf("%.1lf", matrix[i][j] );
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
	Matrix strassen( Matrix a , Matrix b )
	{
		if( a.line <= 1 || a.collumn <= 1 || b.line <= 1 || b.collumn <= 1 )
			return a * b;

		Matrix r = Matrix( a.line , b.collumn );
		Matrix a11( a.line/2 , a.collumn/2 ) , a12( a.line/2 , a.collumn/2 ) , 
					a21( a.line/2 , a.collumn/2 ) , a22( a.line/2 , a.collumn/2 );
		Matrix b11( b.line/2 , b.collumn/2 ) , b12( b.line/2 , b.collumn/2 ) , 
				b21( b.line/2 , b.collumn/2 ) , b22( b.line/2 , b.collumn/2 );
		// Copiando as matrizes
		int la = a.line/2 , ca = a.collumn/2;
		int lb = b.line/2 , cb = b.collumn/2;
		for (int i = 0; i < la ; ++i)
		 for (int j = 0; j < ca ; ++j)
		 {
		 	a11.matrix[i][j] = a.matrix[i][j];
		 	a12.matrix[i][j] = a.matrix[i][j+ca];
		 	a21.matrix[i][j] = a.matrix[i+la][j];
		 	a22.matrix[i][j] = a.matrix[i+la][j+ca];
		 }
		for (int i = 0; i < lb ; ++i)
		 for (int j = 0; j < cb ; ++j)
		 {
		 	b11.matrix[i][j] = b.matrix[i][j];
		 	b12.matrix[i][j] = b.matrix[i][j+cb];
		 	b21.matrix[i][j] = b.matrix[i+lb][j];
		 	b22.matrix[i][j] = b.matrix[i+lb][j+cb];
		 } 
		// Multiplicações
		Matrix p1 = strassen( a11, b12-b22 );		Matrix p2 = strassen( a11+a12 , b22 );		Matrix p3 = strassen( a21+a22 , b11 );
		Matrix p4 = strassen( a22 , b21-b11 );		Matrix p5 = strassen( a11+a22 , b11+b22 );		Matrix p6 = strassen( a12-a22 , b21+b22 );
		Matrix p7 = strassen( a11-a21 , b11+b12 );
		// Resultados parciais
		Matrix c11 = p5 + p4 - p2 + p6;			Matrix c12 = p1 + p2;
		Matrix c21 = p3 + p4;					Matrix c22 = p5 + p1 - p3 - p7;
		// Transferencia
		for (int i = 0; i < la ; ++i)
		 for (int j = 0; j < cb ; ++j)
		 {
		 	r.matrix[i][j] = c11.matrix[i][j];
		 	r.matrix[i+la][j] = c21.matrix[i][j];
		 	r.matrix[i][j+cb] = c12.matrix[i][j];
		 	r.matrix[i+la][j+cb] = c22.matrix[i][j];
		 }
		return r;
	}
};
int main()
{
	Matrix a(2,2), b(2,2), c, d;
/*
	a.matrix[0][0] = 1;	a.matrix[0][1] = 3;
	a.matrix[1][0] = 7;	a.matrix[1][1] = 5;
	cout << "Matriz A" << endl;
	a.print();
	
	b.matrix[0][0] = 6;	b.matrix[0][1] = 8;
	b.matrix[1][0] = 4;	b.matrix[1][1] = 2;
	cout << "Matriz B" << endl;
	b.print();
// Teste básico	

	cout << "Multiplicação normal" << endl;
	c = a * b;
	c.print();

	cout << endl << "Multiplicação strassen" << endl;
	d = d.strassen(a,b);
	d.print();
*/

	int l1, l2, l3;
	srand (time(NULL));
	l2 = l3 = l1 = rand()%6;
	l2 = rand()%6; 
	l3 = rand()%6;
	Matrix e(1<<l1,1<<l2) , f(1<<l2,1<<l3);
	for (int i = 0; i < 1<<l1 ; ++i)
		for (int j = 0; j < 1<<l2 ; ++j)
			e.matrix[i][j] = rand()%30;
	for (int i = 0; i < 1<<l2 ; ++i)
		for (int j = 0; j < 1<<l3 ; ++j)
			f.matrix[i][j] = rand()%30;

	c = e * f;
	cout << "Multiplicação normal" << endl;
	c.print();
	cout << endl << "Multiplicação strassen" << endl;
	d = d.strassen(e,f);
	d.print();

	return 0;
}
