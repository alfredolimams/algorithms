#include <stdio.h>
#include <string.h>
#define MAX 12
#define DEBUG if(0)

void cands( int a[] , int cand[] , int n, int *ncand, int k )
{
	DEBUG printf("MEUS CANDITADOS");
	int qt = 0, i;
	for( i = 1 ; i <= n ; ++i )
	{
			if( a[i] == 0 )
			{
				cand[qt++] = i;
			}
	}
	DEBUG printf("  %d\n", qt);
	DEBUG for( i = 0 ; i < qt ; ++i )
	{
		printf("%d ", cand[i]);
	}
	*ncand = qt;
}

int is_solution( int k , int n )
{
	return k == n;
}

void process( int ans[] , int n )
{
	int i;
	DEBUG printf("ENTROU\n");
	for( i = 0 ; i < n ; ++i )
		printf("%d", ans[i]);
	printf("\n");
}

void bt( int k , int n , int ans[] , int a[] )
{
	DEBUG printf("---%d----\n", k );
	if( is_solution(k,n) )
		process(ans,n);
	else
	{
		int cand[MAX], ncand, i;
		cands( a , cand, n , &ncand , k);
		for( i = 0 ; i < ncand ; ++i )
		{
			a[ cand[i] ] = 1;
			DEBUG printf("Atrabuindo na posicao %d o valor %d\n", k , cand[i]);
			ans[k] = cand[i];
			bt( k+1 , n , ans , a );
			a[ cand[i] ] = 0;
		}
	}
}
main()
{
	int n;
	scanf("%d", &n);
	int ans[n+1], a[n+1];
	memset( a , 0 , sizeof a );
	bt( 0, n , ans , a );
}
