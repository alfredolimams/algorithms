#include <stdio.h>

struct item
{
	int peso;
	int valor;
};

int max( int a , int b )
{
	if( a > b )
		return a;
	return b; 
}
int mochila( int idx , int n , int peso , int valor , struct item itens[] )
{
	if( idx == n )
	{
		if( peso < 0 )
		{
			return 0;
		}
		return valor;
	}
	else
	{
		return max( mochila(idx+1,n, peso,valor,itens) , mochila(idx+1,n,peso - itens[idx].peso , valor + itens[idx].valor , itens ) );
	}
}
int main(int argc, char const *argv[])
{
	int quantidade, capacidade;
	scanf("%d%d", &quantidade, &capacidade);
	struct item itens[quantidade];
	int i;
	for ( i = 0; i < quantidade ; ++i)
	{
		scanf("%d" , &itens[i].valor );
	}
	for ( i = 0; i < quantidade ; ++i)
	{
		scanf("%d" , &itens[i].peso );
	}

	printf("%d\n",  mochila(0,quantidade,capacidade,0,itens) );

	return 0;
}
