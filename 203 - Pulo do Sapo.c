#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int pedras , sapos;
	scanf("%d%d", &pedras , &sapos);
	int atual , pulos;
	int pedra[pedras];
	int i;
	memset( pedra , 0 , sizeof pedra );
	int idx1 , idx2;
	for (i = 0; i < sapos; ++i)
	{
		scanf("%d%d", &atual , &pulos);
		idx1 = idx2 = atual-1;
		while( idx1 >= 0 || idx2 < pedras )
		{
			if( idx1 >= 0 )
				pedra[idx1] = 1;
			if( idx2 < pedras )
				pedra[idx2] = 1;
			idx1 -= pulos;
			idx2 += pulos;
			if( !pulos ) break;
		}
	}
	for ( i = 0; i < pedras; ++i)
		printf("%d\n", pedra[i]);
	return 0;
}
