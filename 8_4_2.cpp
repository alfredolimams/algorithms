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
#define DEG_to_RAD(x) (x/180.0)*M_PI
#define RAD_to_DEG(x) (x*180.0)/M_PI
#define MIN_to_DEG(x) x/60.0
#define in( l1, x, l2 ) l1 <= x && x <= l2 ? true : false
#define EQUAL(a,b) fabs(a-b) < EPS

bool have;
vi cycles;
vi vstd;
vi parent;
vi dist;
vvii AdjList;

void cycle(int u, int t) 
{
    /* 
        O ( V + E );
    */
    vstd[u] = EXPLORED;
    dist[u] = t;
    for ( auto v : AdjList[u] )
    {
        if (vstd[v.first] == UNVISITED)
        {
            parent[v.first] = u;
            cycle(v.first, t + v.second );
        }
        else if (vstd[v.first] == EXPLORED) 
        {
            if ( v.first != parent[u] )
            {
                int q = u;
                have = true;
                DEBUG  cout << "CYCLE ";
                while( parent[q] != parent[v.first] )
                {
                    DEBUG printf("%d ", q+1 );
                    cycles[q] = dist[u] - dist[v.first] + v.second;
                    q = parent[q];
                }
                cycles[q] = dist[u] - dist[v.first] + v.second;
                DEBUG printf("%d = %d\n", q+1, dist[u] - dist[v.first] + v.second);
            }
        }
    }
    vstd[u] = VISITED;
}

int main(int argc, char const *argv[])
{
    have = false;
    int vertices, arestas;
    cin >> vertices >> arestas;
    int saida , entrada;
    init(vertices);
    for( int i = 0 ; i < arestas ; ++i )
    {
        cin >> saida >> entrada;
        AdjList[ saida ].pb( { entrada, 0 } );
    }
    for( int  i = 0 ; i < vertices && !have ; ++i )
        if( vstd[i] == UNVISITED )
            cycle(i,0);
    return 0;
}
