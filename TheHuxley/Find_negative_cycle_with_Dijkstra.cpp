#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int,ii> iii;
#define pb push_back
#define fi first
#define se second
#define INF 0xf3f3f3
#define DEBUG if(0)
vvii AdjList;
void init(int vertex)
{
	AdjList.clear();
	AdjList.resize(vertex);
}
bool dijkstra( int vertex, int from )
{
	vii dist(vertex, ii(INF,INF) );
	dist[from] = ii(0,0);
	priority_queue< iii, vector<iii>, greater<iii> > pq; pq.push( iii(0, ii(from, 0)) );
	while( !pq.empty() )
	{
		iii front = pq.top(); pq.pop();
		int d = front.first, u = front.second.fi , s = front.second.se;
		if (d > dist[u].fi) continue;
		for( auto p : AdjList[u] )
		{
			ii v = p;
			if( dist[u].fi + v.se < dist[v.fi].fi )
			{
				dist[v.fi].fi = dist[u].fi + v.se;
				dist[v.fi].se = dist[u].se + 1;
				if( dist[v.fi].se == vertex ) return true;
				pq.push( iii(dist[v.fi].fi, ii(v.fi, dist[v.fi].se )) );
			}
		}
	}
	return false;
}
int main()
{
	int tc;
	cin >> tc;
	while( tc-- )
	{
		int v , e;
		int f , a , c;
		cin >> v >> e;
		init(v);
		for( int i = 0 ; i < e ; ++i )
		{
			cin >> f >> a >> c;
			AdjList[f].pb({a,c});
		}
		for( int i = 0 ; i < v ; ++i )
			if( dijkstra(v,i) )
			{
				cout << "possible" << endl;
				goto loop;
			}
		cout << "not possible" << endl;
loop:;
	}
	return 0;
}
