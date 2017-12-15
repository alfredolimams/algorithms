#include <stdio.h>
#include <string.h>

int MT[2][110][110];

int vx[] = {1,1,0,-1,-1};
int vy[] = {-1,1,0,-1,1};

int pos( int p , int size )
{
	while( p >= size ) p -= size;
	while( p < 0 ) p += size;
	return p;
}

void print( int id , int linha, int coluna )
{
	int i , j;
	for (i = 0; i < linha ; ++i)
	{
		for( j = 0 ; j < coluna ; ++j )
		{
			if( j ) printf(" ");
			printf("%d", MT[id][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void move ( int id , int linha, int coluna )
{
	int i , j;
	for (i = 0; i < linha ; ++i)
		for( j = 0 ; j < coluna ; ++j )
			MT[1-id][pos(i-1,linha)][pos(j+1,coluna)] = MT[id][i][j];
}

int main(int argc, char const *argv[])
{
	int N, M;
	int K;
	int H, B;
	memset( MT , 0 , sizeof MT );
	int i, j, k;
	scanf("%d%d%d", &N , &M , &K);
	int x , y;
	for (i = 0; i < K ; ++i)
	{
		scanf("%d%d", &x , &y);
		MT[0][x][y] = 1;
	}
	print(0,N,M);
	int id = 0;
	scanf("%d%d", &H, &B);
	for (i = 0; i < H ; ++i)
	{
		for (j = 0; j < B ; ++j)
		{
			scanf("%d%d", &x , &y);
			for( k = 0 ; k < 5 ; ++k )
				MT[id][pos(x+vx[k],N)][pos(y+vy[k],M)] = 0;
		}
		move(id, N ,M);
		id = 1 - id;
		print(id, N, M);
	}
	return 0;
}
