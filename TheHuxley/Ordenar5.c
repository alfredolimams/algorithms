#include <stdio.h>

int main()
{
	int n1 , n2 , n3, n4 , n5 , aux;
	scanf("%d%d%d%d%d", &n1 , &n2 , &n3 , &n4, &n5 );
	if( n1 > n2 )
	{
		aux = n1;
		n1 = n2;
		n2 = aux;
	}
	if( n1 > n3 )
	{
		aux = n1;
		n1 = n3;
		n3 = aux;
	}
	if( n1 > n4 )
	{
		aux = n1;
		n1 = n4;
		n4 = aux;
	}
	if( n1 > n5 )
	{
		aux = n1;
		n1 = n5;
		n5 = aux;
	}
	if( n2 > n3 )
	{
		aux = n2;
		n2 = n3;
		n3 = aux;
	}
	if( n2 > n4 )
	{
		aux = n2;
		n2 = n4;
		n4 = aux;
	}
	if( n2 > n5 )
	{
		aux = n2;
		n2 = n5;
		n5 = aux;
	}
	if( n3 > n4 )
	{
		aux = n3;
		n3 = n4;
		n4 = aux;
	}
	if( n3 > n5 )
	{
		aux = n3;
		n3 = n5;
		n5 = aux;
	}
	if( n4 > n5 )
	{
		aux = n4;
		n4 = n5;
		n5 = aux;
	}
	return 0;
}
