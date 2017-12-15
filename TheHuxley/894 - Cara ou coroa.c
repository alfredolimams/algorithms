#include <stdio.h>
#include <math.h>



void moedas( int qt_moedas , int max_moedas , int caras, int coroas, int * ans , int diff )
{
	// Caso base: ter todas as moedas
	if( qt_moedas == max_moedas )
	{
		// Completou e a diferença é igual a D
		if( diff == abs(caras-coroas) )
		{
			++(*ans);
		}
		else
		{
			// Não precisamos fazer nd aqui ;-P
		}
	}
	else
	{
		// Precisamos colocar mais uma moeda uma vez de cara ou vezes de coroa
		//Colocando cara
		moedas( qt_moedas+1, max_moedas , caras+1 , coroas, ans , diff );
		// Colocando coroa
		moedas( qt_moedas+1, max_moedas , caras , coroas+1, ans , diff );
	}
}

int main(int argc, char const *argv[])
{
	int qt_moeda, diferenca;
	scanf("%d%d", &qt_moeda, &diferenca);
	int ans = 0;
	// Chamamos com nenhuma moeda, então cara e coroa = 0
	moedas( 0, qt_moeda , 0 , 0 , &ans , diferenca );
	printf("%d\n", ans);
	return 0;
}
