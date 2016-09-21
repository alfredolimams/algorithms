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
int mochila( int idx , int n , int peso , struct item itens[] )
{
	if( idx == n )
		return 0;
	else if( itens[idx].peso > peso ) 
		return mochila(idx+1, n , peso, itens);
	else
		return max( mochila(idx+1, n , peso, itens) , itens[idx].valor + mochila(idx+1,n,peso - itens[idx].peso, itens) );
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

	printf("%d\n", mochila(0,quantidade,capacidade,itens) );

	return 0;
}
