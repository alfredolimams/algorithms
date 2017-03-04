#include <stdio.h>

int main()
{
	int A, B, C, aux;
	scanf("%d%d%d", &A, &B, &C);
//	Ordenando	
	if( A < B )
	{
		aux = A;
		A = B;
		B = aux;
	}
	if( A < C )
	{
		aux = A;
		A = C;
		C = aux;
	}
	if( B < C )
	{
		aux = B;
		B = C;
		C = aux;
	}


	if( A == B || B == C || C+B == A )
	{
		printf("S\n");
	}
	else
	{
		printf("N\n");
	}
}
