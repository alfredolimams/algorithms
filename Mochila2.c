#include <stdio.h>

struct item
{
	int peso;
	int valor;
};

void mochila( int idx , int n , int peso , int valor , int * ans , struct item itens[] )
{
	if( idx == n )
	{
		if( peso >= 0 )
		{
			if( *ans < valor )
			{
				*ans = valor;
			}
		}
	}
	else
	{
		mochila( idx+1 , n, peso , valor, ans , itens );
		mochila( idx+1 , n, peso - itens[idx].peso , valor + itens[idx].valor , ans , itens );
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

	int ans = 0;

	mochila( 0, quantidade , capacidade , 0 , &ans , itens );

	printf("%d\n", ans);

	return 0;
}
