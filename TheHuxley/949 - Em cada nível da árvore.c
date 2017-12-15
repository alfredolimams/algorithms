#include<stdio.h>


int max( int a , int b )
{
	if( a > b )
		return a;
	return b;
}

int min( int a , int b )
{
	if( a < b )
		return a;
	return b;
}

struct tree
{
	int v;
	int l;
	int r;
};

int arv( int idx , int depth, struct tree t[] , int ans[][2] ) {
	
	int a = 0;
	ans[depth][0] = min( t[idx].v , ans[depth][0] );
	ans[depth][1] = max( t[idx].v , ans[depth][1] );
	if( t[idx].l != -1 )
		a = max(a , arv( t[idx].l, depth+1, t ,ans) );
	if( t[idx].r != -1 )
		a = max(a , arv( t[idx].r, depth+1, t ,ans) );
	return 1 + a;
}

main()
{
	int num;
	int i = i;
	int ans[num+10][2];
	struct tree trees[num+10];
	scanf("%d", &num);
	for( i = 0 ; i < num ; ++i ) {
		ans[i][0] = 1<<20; // Numero 2 elevado a 20 ( Infinito )
		ans[i][1] = 0;
	}
	for( i = 0 ; i < num ; ++i ) {
		scanf("%d%d%d", &trees[i].v , &trees[i].l , &trees[i].r);
	}
	int alt = arv( 0, 0, trees, ans );
	for( i = 0 ; i < alt ; ++i )
		printf("Nivel %d: Maior = %d, Menor = %d\n", i+1 , ans[i][1] , ans[i][0] );
}
