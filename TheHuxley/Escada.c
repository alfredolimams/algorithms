#include <stdio.h>

int main()
{
	int n, i;
	int time_count = 0;
	int t = 0, l;
	scanf("%d", &n); 	// Quantidade que o sensor foi ativado
	scanf("%d", &t);	// Leitura do sensor ativado
	for( i = 0 ; i < n-1 ; ++i )
	{
		scanf("%d", &l);	// Leitura do sensor ativado
		if( t + 10 >= l ) 	// Se antes de terminar o sensor for ativado novamente
			time_count += ( l - t ); 
		else				// Escada desligada 
			time_count += 10;
		t = l;				// Atualização do tempo
	}
	printf("%d\n", time_count+10);
}
