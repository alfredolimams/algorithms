#include <stdio.h>
#define DEBUG if(0)

int find ( int A[] , int size )
{
	int i , ans = 0;
	for( i = 1 ; i < size ; ++i )
	{
		if( A[i] < A[ans] )
		{
			ans = i;
		}
	}
	return ans;
}

void print( int B[] , int n  )
{
	int i;
	for( i = 0 ; i < n ; ++i )
	{
		if( i ) printf(" ");
		printf("%d", B[i]);
	}
	printf("\n");
}

int pos( int x , int n )
{
	while ( x < 0 )
		x += n;
	while ( x >= n )
		x -= n;
	return x;
}

int main(int argc, char const *argv[])
{
	int N, Q;
	scanf("%d%d", &N , &Q);
	int celulas[N];
	int ans[Q+1][N];
	int i;
	for ( i = 0 ; i < N ; ++i )
	{
		scanf("%d", &celulas[i]);
	}
	int p = find( celulas, N );
	for( i = 0 ; i < N ; ++i )
	{
		ans[0][i] = celulas[ (p+i)%N ];
	}
	DEBUG printf("||");
	DEBUG print(ans[0],N);
	DEBUG printf("||");
	int uniao;
	int j;
	for ( i = 0; i < Q ; ++i)
	{
		scanf("%d", &uniao);
		DEBUG printf("|%d ", uniao);
		DEBUG printf("%d %d|\n", ans[i][pos(uniao,N-i)], ans[i][pos(uniao+1,N-i)] );
		celulas[0] = ans[i][pos(uniao,N-i)] + ans[i][pos(uniao+1,N-i)];
		for ( j = 1; j <= N-i-2 ; ++j)
		{
			celulas[j] = ans[i][pos(uniao+1+j,N-i)];
		}
		DEBUG printf("|||");
		DEBUG print(celulas, N-i-1 );
		DEBUG printf("|||\n");
		int inicial = find( celulas , N-i-1 );
		DEBUG printf("----%d----", inicial);
		for( j = 0 ; j < N-i-1 ; ++j )
		{
			ans[i+1][j] = celulas[ (inicial+j)%(N-i-1)];
		}
		DEBUG printf("####");
		DEBUG print(ans[i+1], N-i-1);
		DEBUG printf("####\n");
	}

	for( i = 0 ; i <= Q ; ++i )
	{
		print( ans[i] , N-i );
	}

	return 0;
}
