#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef pair<ll,ll> llll;

#define pb push_back
#define fi first
#define se second
#define DEBUG if(0)
#define VISITED 2
#define EXPLORED 1
#define UNVISITED 0
#define pb push_back
#define EPS 1e-9
#define INF 1<<20
#define inf 0x3f3f3f3f
#define DEG_to_RAD(x) M_PI*(x)/(180.0)
#define RAD_to_DEG(x) (x*180.0)/M_PI
#define MIN_to_DEG(x) x/60.0
#define in( l1, x, l2 ) l1 <= x && x <= l2 ? true : false
#define EQUAL(a,b) fabs(a-b) < EPS
#define all(x) (x).begin() , (x).end()

string ans;
char A[210][210];


bool equal( int beginx , int endx , int beginy , int endy )
{
	char ref = A[beginx][beginy];
	for (int i = beginx ; i < endx ; ++i)
		for (int j = beginy ; j < endy ; ++j)
			if( ref != A[i][j] )
				return false;
	return true;
}

void div( int bx , int ex , int by , int ey )
{
	DEBUG cout << bx << " " << ex << " " << by << " " << ey; ;
	if( bx == ex || by ==  ey  )
		return;
	if( equal( bx , ex , by , ey ) )
	{
		DEBUG cout << " GO" << endl;
		ans += A[bx][by];
	}
	else
	{
		DEBUG cout << endl;
		ans += "D";
		int divx = ((ex-bx)+1)/2, divy = ((ey-by)+1)/2;  
		div( bx , bx+divx , by , by + divy );
		div( bx , bx+divx , by + divy , ey );
		div( bx+divx , ex , by , by + divy );
		div( bx+divx , ex , by + divy , ey );
	}
}

int main(int argc, char const *argv[])
{
	int qt;
	cin >> qt;
	while( qt-- )
	{
		int l, c;
		cin >> l >> c;
		ans = "";
		for (int i = 0; i < l ; ++i)
			cin >> A[i];
		DEBUG for (int i = 0; i < l ; ++i)
			cout << A[i] << endl;
		div( 0 , l , 0 , c );
		for (int i = 0; i < ans.size() ; ++i)
		{
			if( i && (i)%50 == 0 ) cout << endl;
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
